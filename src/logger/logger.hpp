#pragma once

#include <string>
#include <spdlog/spdlog.h>
#include <memory>
class Logger
{
private:
    std::string _name;
    std::shared_ptr<spdlog::logger> _logger;

public:
    Logger(std::string logger_name = "crypta", bool to_file = true);
    ~Logger();

    void to_file(std::string dir);

    template <class... Args>
    void info(Args... msg);

    template <class... Args>
    void debug(Args... msg);

    template <class... Args>
    void error(Args... msg);

    template <class... Args>
    void warn(Args... msg);

    template <class... Args>
    void critical(Args... msg);
};

template <class... Args>
void Logger::info(Args... msg)
{
    _logger->info(msg...);
}

template <class... Args>
void Logger::debug(Args... msg)
{
    _logger->debug(msg...);
}

template <class... Args>
void Logger::error(Args... msg)
{
    _logger->error(msg...);
}

template <class... Args>
void Logger::warn(Args... msg)
{
    _logger->warn(msg...);
}
template <class... Args>
void Logger::critical(Args... msg)
{
    _logger->critical(msg...);
}
