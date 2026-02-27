#include <memory>
#include "fluxlog/logger.hpp"
#include "fluxlog/formatter/simple_formatter.hpp"
#include "fluxlog/sink/console_sink.hpp"

int main() {

    
    auto formatter = std::make_shared<fluxlog::SimpleFormatter>();
    auto consoleSink = std::make_shared<fluxlog::ConsoleSink>();

    fluxlog::Logger log;
    log.addSink(consoleSink);
    log.setFormatter(formatter);
    
    log.log(fluxlog::LogLevel::Info,"Application Started",__FILE__,__LINE__);
}
