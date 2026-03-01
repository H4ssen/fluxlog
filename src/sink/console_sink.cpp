#include "sink/console_sink.hpp"
#include "formatter/i_formatter.hpp"
#include <iostream>
#include <memory>

namespace fluxlog {

    void
    ConsoleSink::log_mt(std::string_view record) {
        if (!formatter_) return;
        std::cout<<record<<std::endl;
    }
}