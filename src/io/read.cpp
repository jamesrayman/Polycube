#include "read.h"

#include <string>
#include <iostream>
#include <fstream>

#include "exceptions.h"

namespace read {
    std::string file (const std::string& fileName) {
        std::ifstream file (fileName);
        std::string res, line;

        if (!file.good()) {
            throw err::FileNotFound(fileName); 
        }

        while (std::getline(file, line)) {
            res += line + "\n";
        }
        return res;
    }

    std::string commandLine (int argc, char** argv, int& solutionLimit, int& printLimit) {
        if (argc < 2) {
            throw err::CliOptions(argv[0]);
        }
        else if (argc == 2) {
            return file(std::string(argv[1]));
        }
        else {
            std::string flags (argv[1]);

            

            return file(std::string(argv[2]));
        }


    }
}