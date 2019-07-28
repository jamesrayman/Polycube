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
        std::string res = "";

        for (int i = 1; i < argc; i++) {
            res += argv[i];
            res += " ";
        }
        res += "\n";

        int hashtagCount = 0;

        for (char c : res) {
            if (c == '#') {
                hashtagCount++;
            }
        }

        while (hashtagCount < 4) {
            std::cout << "> ";

            std::string line;
            std::getline(std::cin, line);

            for (char c : line) {
                if (c == '#') {
                    hashtagCount++;
                }
            }

            res += line + "\n";
        }

        return res;
    }
}