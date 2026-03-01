#pragma once

#include <chrono>
#include <string>
#include <thread>
#include <string_view>
#include "log_level.hpp"

namespace fluxlog {
    struct LogRecord{
        LogLevel level;
        std::string_view message;
        std::chrono::time_point<std::chrono::system_clock> timestamp;
        std::string_view file;
        int line;
    };
}