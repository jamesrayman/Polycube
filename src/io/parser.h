#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../polycube/block.h"
#include "../polycube/block_list.h"
#include "../polycube/board.h"

std::vector<Board<3>> parse (const std::string&);

std::unordered_map<std::string, Block<3>> parseImport (const std::string&, std::unordered_set<std::string>&);
Block<3> parseBlock (const std::string&);
BlockList<3> parseBlockList (const std::string&, const std::unordered_map<std::string, Block<3>>&);