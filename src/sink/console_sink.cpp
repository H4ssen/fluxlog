#include "sink/console_sink.hpp"
#include <iostream>

namespace fluxlog {
    void
    ConsoleSink::write(const std::string& message) {
        std::cout<<message<<std::endl;
    }
}