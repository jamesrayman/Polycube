#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../polycube/polycube.h"
#include "../polycube/polycube_list.h"
#include "../polycube/board.h"

std::vector<Board<3>> parse (const std::string&);

std::unordered_map<std::string, Polycube<3>> parseImport (const std::string&, std::unordered_set<std::string>&);
Polycube<3> parsePolycube (const std::string&);
PolycubeList<3> parsePolycubeList (const std::string&, const std::unordered_map<std::string, Polycube<3>>&);