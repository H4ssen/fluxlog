#pragma once 
#include "formatter/i_formatter.hpp"
namespace fluxlog {
    class SimpleFormatter : public IFormatter {
        virtual std::string format(const LogRecord& record) override;
    };
}