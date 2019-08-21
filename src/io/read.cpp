#include "read.h"

#include <string>
#include <iostream>
#include <fstream>

namespace read {
    std::string file (const std::string& fileName) {
        std::ifstream file (fileName);
        std::string res, line;

        while (std::getline(file, line)) {
            res += line + "\n";
        }
        return res;
    }

    std::string commandLine (int argc, char** argv) {
        if (argc != 2) {
            throw std::string("Include file name");
        }
        
        if (argc == 2) {
            return file(std::string(argv[1]));
        }


    }
}