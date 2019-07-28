#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../polycube/polycube.h"
#include "../polycube/polycube_list.h"
#include "../polycube/board.h"
#include "../polycube/puzzle.h"

namespace parse {
    Puzzle<3> puzzle (const std::string&);
    std::unordered_map<std::string, Polycube<3>> import (const std::string&, std::unordered_set<std::string>&);
    Polycube<3> polycube (const std::string&);
    Board<3> board (const std::string&);
    PolycubeList<3> polycubeList (const std::string&, const std::unordered_map<std::string, Polycube<3>>&);
}

