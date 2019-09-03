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
            throw std::string("File \"") + fileName + "\" does not exist.\n"; 
        }

        while (std::getline(file, line)) {
            res += line + "\n";
        }
        return res;
    }

    std::string commandLine (int argc, char** argv, int& solutionLimit, int& printLimit) {
        if (argc < 2) {
            throw std::string("Usage:   ") + argv[0] + " [-cnf] [SOLUTIONLIMIT] FILENAME\n";
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