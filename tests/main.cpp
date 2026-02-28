#include <memory>
#include "fluxlog/logger.hpp"
#include "fluxlog/formatter/simple_formatter.hpp"
#include "fluxlog/sink/console_sink.hpp"
#include "fluxlog/formatter/simple_formatter.hpp"

int main() {

    
    auto sink1 = std::make_shared<fluxlog::ConsoleSink>(std::make_unique<fluxlog::SimpleFormatter>());
    fluxlog::Logger logger(sink1);
    
    logger.log(fluxlog::LogLevel::Info,"Application Started",__FILE__,__LINE__);
}
