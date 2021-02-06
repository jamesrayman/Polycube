#pragma once

#include <string>

namespace read {
    std::string file (const std::string&);
    std::string commandLine (int, char**, bool&, int&, int&);
}
