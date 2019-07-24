#pragma once

#include <string>

namespace util {
    std::string readFile (const std::string&);
    std::string readCommandLine (int, char**);
}
