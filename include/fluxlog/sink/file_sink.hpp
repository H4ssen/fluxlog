#pragma once
#include <fstream>
#include "i_sink.hpp"

namespace fluxlog {
    class FileSink : public ISink {
        public:
            explicit FileSink(const std::string& filename) : file_(filename){
                if (!file_) {
                    throw std::runtime_error("Failed to open file");
                }
            };
            void write(LogRecord record) override;
        private:
            std::ofstream file_;
    };
}