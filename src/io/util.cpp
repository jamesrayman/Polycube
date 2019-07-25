#include "util.h"

#include <string>
#include <iostream>
#include <fstream>

namespace util {
    std::string readFile (const std::string& fileName) {

    }

    std::string readCommandLine (int argc, char** argv) {
        std::string res = "";

        for (int i = 1; i < argc; i++) {
            res += argv[i];
            res += " ";
        }

        return res;
    }
}