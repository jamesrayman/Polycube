#include "format.h"

#include <string>

#include "../polycube/board.h"

namespace format {
    std::string board (const Board<3>& b) {
        std::string res = "";
        auto shape = b.shape();

        for (const auto& i : b.allPositions()) {
            res += std::to_string(b[i]);

            if (i[2] == shape[2] - 1) {
                if (i[1] == shape[1] - 1) res += "\n";
                else res += " ";
            }
        }

        return res;
    }

    std::string solutions (const std::vector<Board<3>>& solutions) {
        std::string res = "";
        
        if (solutions.size() == 0) {
            res += "There are no solutions.\n";
        }
        else if (solutions.size() == 1) {
            res += "There is 1 solutions, not counting rotations and reflections: \n\n";
        
            res += board(solutions[0]);
        }
        else {
            res += "There are " + std::to_string(solutions.size()) + " solutions, not counting rotations and reflections: \n\n";

            for (int i = 0; i < solutions.size(); i++) {
                res += "Solution #" + std::to_string(i+1) + "\n";

                res += board(solutions[i]) + "\n";
            } 
        }

        return res;
     }
}