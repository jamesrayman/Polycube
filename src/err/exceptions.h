#pragma once

#include <exception>
#include <string>

namespace err {

    class CliOptions : public std::exception {
    private:
        std::string arg;
    public:
        CliOptions (const std::string&);
        virtual const char* what() const throw();
    };

    class FileNotFound : public std::exception {
    private:
        std::string file;
    public:
        FileNotFound (const std::string&);
        virtual const char* what() const throw();
    };

    class PuzzleFormat : public std::exception {
    private:
        std::string message;
    public:
        PuzzleFormat (const std::string&);
        virtual const char* what() const throw();
    };

    class PolycubeName : public std::exception {
    private:
        std::string polycube;
    public:
        PolycubeName (const std::string&);
        virtual const char* what() const throw();
    };

    class PolycubeNotFound : public std::exception {
    private:
        std::string polycube;
    public:
        PolycubeNotFound (const std::string&);
        virtual const char* what() const throw();
    };

    class PolycubeRedefinition : public std::exception {
    private:
        std::string polycube;
    public:
        PolycubeRedefinition (const std::string&);
        virtual const char* what() const throw();
    };
}