#pragma once
#include <string>
#include "log_record.hpp"

namespace fluxlog{
    class ISink {
        public:
            virtual ~ISink() = default;
            virtual void write(LogRecord record) = 0;
    };
}