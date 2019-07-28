#pragma once

#include <string>
#include <vector>

#include "../polycube/board.h"

namespace format {
    std::string solutions (const std::vector<Board<3>>&);
    std::string board (const Board<3>&);
}