#include "logger/logger.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"
#include <boost/filesystem.hpp>
#include <memory>
#include <string>
#include <assert.h>
#include "ftx/util/time.hpp"
#include <iostream>

namespace fs = boost::filesystem;

Logger::Logger(std::string name, bool to_file)
{
    std::vector<spdlog::sink_ptr> sinks;

    using colored_sink = spdlog::sinks::stdout_color_sink_mt;
    using rotated_sink = spdlog::sinks::rotating_file_sink_mt;

    auto console_sink = std::make_shared<colored_sink>();
    console_sink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %v%$");
    sinks.emplace_back(console_sink);

    if (to_file)
    {
        auto path = fs::current_path() / "logs";
        fs::create_directory(path);

        path /= util::strftime_now("%Y-%m-%d") + ".log";
        auto file_sink = std::make_shared<rotated_sink>(
            path.string(), /* filename */
            1048576 * 100, /* max_file_size */
            100,           /* max_files */
            false          /* rotate_on_open */
        );
        sinks.emplace_back(file_sink);
    }
    _logger = std::make_shared<spdlog::logger>(
        name,
        sinks.begin(),
        sinks.end()
    );
    _logger->set_level(spdlog::level::trace);
    _logger->flush_on(spdlog::level::trace);
    spdlog::register_logger(_logger);
}

Logger::~Logger()
{
    spdlog::shutdown();
}
