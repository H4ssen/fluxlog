
#include <string>
#include <chrono>
#include <thread>
#include <filesystem>
#include <functional>
#include <string_view>
#include "logger.hpp"
#include "log_level.hpp"
#include "log_record.hpp"
#include "formatter/i_formatter.hpp"
#include "formatter/simple_formatter.hpp"

namespace fluxlog {

    constexpr std::string_view basename(std::string_view path) 
    {
        size_t pos = path.find_last_of("/\\");
        return (pos == std::string_view::npos ?
                path
                : path.substr(pos +1));
    }

    void 
    Logger::log(LogLevel level,
                 std::string_view message,
                 const char* file, int line) 
    {   
        if (level < minLevel_) return;

        LogRecord record = createLogRecord(level,message,file,line);

        for (const auto& sink : sinks_) {
            sink->log(record);
        }

    }

    Logger::Logger(std::shared_ptr<ISink> sink) 
    { 
            sinks_.push_back(sink);
            minLevel_ = LogLevel::Info;//Default min level
    }

    LogRecord
    Logger::createLogRecord(LogLevel level, std::string_view message, const char* file, int line) {
        LogRecord record;
        record.level = level;
        record.message = message;
        record.timestamp = std::chrono::system_clock::now();
        record.file = basename(file);
        record.line = line;
        return record;
    }

    void
    Logger::addSink(std::shared_ptr<ISink> sink) {
        sinks_.push_back(sink);
    }

    void 
    Logger::setMinLevel(LogLevel minLevel) {
        minLevel_ = minLevel;
    }

    LogLevel
    Logger::getMinLevel()const {
        return minLevel_;
    }

}
