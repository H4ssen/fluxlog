#include <sstream>
#include <string_view>
#include <chrono>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/format.h>
#include "formatter/simple_formatter.hpp"
#include "log_record.hpp"

namespace fluxlog {
    constexpr std::string_view
    to_string(LogLevel level) {
        switch (level)
        {
        case LogLevel::Info : return "Info";
        case LogLevel::Debug : return "Debug";
        case LogLevel::Error : return "Error";
        case LogLevel::Fatal : return "Fatal";
        case LogLevel::Trace : return "Trace";
        case LogLevel::Warn : return "Warning";
        default : return "Info";
        }
            
    }

    std::string
    getTimeStr(std::chrono::time_point<std::chrono::system_clock> timestamp) 
    { 
        std::time_t now_c = std::chrono::system_clock::to_time_t(timestamp);
        std::tm tm = *std::localtime(&now_c);

        return fmt::format("{:04}-{:02}-{:02} {:02}:{:02}:{:02}",
                                    tm.tm_year + 1900,
                                    tm.tm_mon + 1,
                                    tm.tm_mday,
                                    tm.tm_hour,
                                    tm.tm_min,
                                    tm.tm_sec);
    }

    std::string
    SimpleFormatter::format(const LogRecord& record)
    {
        std::string timeStr = getTimeStr(record.timestamp);
    
        std::string formatted_record = fmt::format("[{}] {} : {} ({} {})\n",
                        to_string(record.level),
                        timeStr,
                        record.message,
                        record.file,
                        record.line);
        return formatted_record;
    }
}