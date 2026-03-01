#pragma once
#include <memory>
#include "sink/i_sink.hpp"
#include "formatter/i_formatter.hpp"

namespace fluxlog {
    class ConsoleSink : public ISink {
        public:
            explicit ConsoleSink(std::unique_ptr<IFormatter> formatter) : formatter_(std::move(formatter)) {}
            void write(LogRecord record) override;
        protected:
            std::unique_ptr<IFormatter> formatter_;
    };
}