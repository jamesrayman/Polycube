#pragma once

#include <string>
#include <vector>

#include "../polycube/board.h"

namespace format {
    std::string cube (int, bool);
    std::string solutions (const std::vector<Board<3>>&, int);
    std::string board (const Board<3>&);
}