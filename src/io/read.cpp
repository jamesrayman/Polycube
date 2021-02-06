#include "read.h"

#include <string>
#include <vector>
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

    std::string commandLine (int argc, char** argv, bool& color, int& solutionLimit, int& printLimit) {
        std::vector<std::string> args;
        std::string fileContents = "";
        bool fileFound = false;

        for (int i = 0; i < argc; i++) {
            args.push_back(argv[i]);
        }
        
        for (int i = 1; i < argc; i++) {
            if (args[i][0] == '-') {
                if (args[i] == "-c") {
                    color = true;
                }
                else if (args[i] == "-n" && i+1 < argc) {
                    i++;
                    try {
                        solutionLimit = std::stoi(args[i]);
                        if (solutionLimit <= 0) solutionLimit = 1e9;
                    }
                    catch (...) {
                        throw err::CliOptions(args[0]);
                    }
                }
                else if (args[i] == "-p" && i+1 < argc) {
                    i++;
                    try {
                        printLimit = std::stoi(args[i]);
                    }
                    catch (...) {
                        throw err::CliOptions(args[0]);
                    }
                }
                else throw err::CliOptions(args[0]);;
            }
            else {
                if (fileFound) throw err::CliOptions(args[0]);

                fileFound = true;
                fileContents = file(args[i]);
            }            
        }

        if (!fileFound) throw err::CliOptions(args[0]);

        printLimit = std::min(printLimit, solutionLimit);

        return fileContents;
    }
}