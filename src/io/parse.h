#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "polycube.h"
#include "board.h"
#include "puzzle.h"

namespace parse {
    Puzzle<3> puzzle (const std::string&);
    std::unordered_map<std::string, Polycube<3>> import (const std::string&, std::unordered_set<std::string>&);
    std::unordered_map<std::string, Polycube<3>> polycubes (const std::string& data);
    Polycube<3> polycube (const std::string&);
    Board<3> board (const std::string&);
    std::vector<Polycube<3>> polycubeList (const std::string&, const std::unordered_map<std::string, Polycube<3>>&);
}

