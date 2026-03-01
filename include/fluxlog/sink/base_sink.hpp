#pragma once
#include <mutex>
#include "sink/i_sink.hpp"
#include "formatter/i_formatter.hpp"

namespace fluxlog {
    class BaseSink : public ISink {
            void log(LogRecord record) final override {
                if (!formatter_) return;
                std::string fmtMsg = formatter_->format(record);
                std::lock_guard<std::mutex> lock(mutex_);
                log_mt(fmtMsg);
            }

        protected:
            virtual void log_mt(std::string_view message) = 0;
            std::unique_ptr<IFormatter> formatter_;

        private:
            std::mutex mutex_;
            
    };
}
