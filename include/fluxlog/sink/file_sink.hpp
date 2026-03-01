#pragma once
#include <fstream>
#include "i_sink.hpp"
#include "base_sink.hpp"

namespace fluxlog {
    class FileSink : public BaseSink {
        public:
            explicit FileSink(const std::string& filename) : file_(filename){
                if (!file_) {
                    throw std::runtime_error("Failed to open file");
                }
            };
            void log_mt(std::string_view record) override;
        private:
            std::ofstream file_;
    };
}