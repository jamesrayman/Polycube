#pragma once

#include <exception>
#include <string>

namespace err {
    class Exception : public std::exception {
    protected:
        std::string message;
    public:
        virtual const char* what() const throw();
    };

    class CliOptions : public Exception {
    public:
        CliOptions (const std::string&);
    };

    class FileNotFound : public Exception {
    public:
        FileNotFound (const std::string&);
    };

    class PuzzleFormat : public Exception {
    public:
        PuzzleFormat (const std::string&);
    };

    class PolycubeName : public Exception {
    public:
        PolycubeName (const std::string&);
    };

    class PolycubeNotFound : public Exception {
    public:
        PolycubeNotFound (const std::string&);
    };

    
}