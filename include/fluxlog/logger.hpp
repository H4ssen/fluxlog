#pragma once
#include <memory>
#include <vector>
#include <string_view>
#include "log_level.hpp"
#include "sink/i_sink.hpp"
#include "formatter/i_formatter.hpp"

namespace fluxlog {
    class Logger {
        public:
            explicit 
            Logger(std::shared_ptr<ISink> sink);
            LogRecord createLogRecord(LogLevel level, std::string_view message,const char* file, int line);
            void log(LogLevel level, std::string_view message, const char* file, int line);
            void addSink(std::shared_ptr<ISink> sink);
            void setMinLevel(LogLevel minLevel);
            LogLevel getMinLevel() const;

        private:
            std::vector<std::shared_ptr<ISink>> sinks_;
            LogLevel minLevel_;
    };
}