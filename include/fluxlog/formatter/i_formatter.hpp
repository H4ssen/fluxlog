#pragma once
#include <string>
#include "log_record.hpp"

namespace fluxlog {
    class IFormatter {
        public:
            virtual ~IFormatter() = default;
            virtual std::string format(const LogRecord& record) = 0;
    };
}