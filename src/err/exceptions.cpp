#include "exceptions.h"

namespace err {
    const char* Exception::what() const throw() {
        return message.c_str();
    }

    CliOptions::CliOptions (const std::string& arg) {
        message = "Usage: " + arg + " [-c] [-n SOLUTIONLIMIT] [-p PRINTLIMIT] PUZZLEFILE\n";
    }
    
    FileNotFound::FileNotFound (const std::string& file) {
        this->message = "File \"" + file + "\" not found.\n";
    }
    
    PuzzleFormat::PuzzleFormat (const std::string& message) {
        this->message = "Puzzle formatting error: " + message + "\n";
    }

    PolycubeName::PolycubeName (const std::string& name) {
        this->message = "\"" + name + "\" is not a valid polycube name.\nPolycube names must be alphanumeric.\n";
    }

    PolycubeNotFound::PolycubeNotFound (const std::string& name) {
        this->message = "Polycube \"" + name + "\" not found.\n";
    }
}