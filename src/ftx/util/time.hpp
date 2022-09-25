#pragma once

#include <chrono>
#include <sstream>
#include <iomanip>

namespace chrono = std::chrono;

namespace util
{

    using Clock = std::chrono::system_clock;
    using TimePoint = chrono::time_point<Clock>;

    inline TimePoint current_time()
    {
        return Clock::now();
    }

    inline chrono::milliseconds get_ms_timestamp(TimePoint time)
    {
        return chrono::duration_cast<chrono::milliseconds>(
            time.time_since_epoch());
    }

    inline std::string strftime_now(std::string format)
    {
        std::stringstream ss;
        TimePoint now = current_time();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm = *std::localtime(&now_c);
        ss << std::put_time(&now_tm, format.c_str());
        return ss.str();
    }

}
