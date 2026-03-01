#pragma once
#include <memory>
#include <mutex>
#include "base_sink.hpp"
#include "formatter/i_formatter.hpp"

namespace fluxlog {
    struct NullMutex {
        void lock() const noexcept {}
        void unlock() const noexcept {}
    };
    class ConsoleSink : public BaseSink {
        public:
            explicit ConsoleSink(std::unique_ptr<IFormatter> formatter)  {
                formatter_ = std::move(formatter);
            }
        protected:
            void log_mt(std::string_view record) override;
    };
}