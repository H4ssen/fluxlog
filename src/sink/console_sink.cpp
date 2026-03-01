#include "sink/console_sink.hpp"
#include "formatter/i_formatter.hpp"
#include <iostream>
#include <memory>

namespace fluxlog {

    void
    ConsoleSink::write(LogRecord record) {
        if (!formatter_) return;
        std::string formattedMessage = formatter_->format(record);
        std::cout<<formattedMessage<<std::endl;
    }
}