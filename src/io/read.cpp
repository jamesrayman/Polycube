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
        if (argc == 2) {
            return file(std::string(argv[1]));
        }

        std::string res = "";

        for (int i = 1; i < argc; i++) {
            res += argv[i];
            res += " ";
        }
        res += "\n";

        int terminatorCount = 0;

        for (char c : res) {
            if (c == '%') {
                terminatorCount++;
            }
        }

        while (terminatorCount < 4) {
            std::cout << "> ";

            std::string line;
            std::getline(std::cin, line);

            for (char c : line) {
                if (c == '%') {
                    terminatorCount++;
                }
            }

            res += line + "\n";
        }

        return res;
    }
}