#include "format.h"

#include <string>

#include "board.h"

namespace format {
    std::string countable (int n, std::string thing, std::string things) {
        if (n == 1) {
            return std::to_string(n) + " " + thing;
        }
        else {
            return std::to_string(n) + " " + things;
        }
    }

    std::string countable (int n, std::string thing) {
        return countable(n, thing, thing + "s");
    }

    std::string cube (int x, bool color) {
        std::string cubeChars = ".@#$%^&*-+=?/~:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (!color) {
            return std::string() + cubeChars[x];
        }

        return "\033[48;5;" + std::to_string(x) + "m\033[38;5;" + std::to_string(x) + "m" + cubeChars[x] + "\033[0m";
    }

    std::string board (const Board<3>& b, bool color) {
        std::string res = "";
        auto shape = b.shape();

        for (const auto& i : b.allPositions()) {
            res += cube(b[i], color);

            if (i[2] == shape[2] - 1) {
                if (i[1] == shape[1] - 1) res += "\n";
                else res += " ";
            }
        }

        return res;
    }

    std::string solutions (const std::vector<Board<3>>& solutions, bool color, int solutionLimit, int printLimit) {
        std::string res = "";
        int solutionsToCount = std::min((int)solutions.size(), solutionLimit);
        int solutionsToPrint = std::min((int)solutions.size(), printLimit);
        
        if (solutionsToCount == 0) {
            res += "There are no solutions.\n";
        }
        else if (solutionsToCount == 1) {
            res += "There is ";
            if (solutionsToCount == solutionLimit) res += "at least ";
            res += "1 solution, excluding rotations and reflections: \n\n";
        
            res += board(solutions[0], color) + "\n";
        }
        else {
            res += "There are ";
            if (solutionsToCount == solutionLimit) res += "at least ";
            res += format::countable(solutionsToCount, "solution");
            res += ", excluding rotations and reflections: \n\n";

            for (int i = 0; i < solutionsToPrint; i++) {
                res += "Solution #" + std::to_string(i+1) + "\n";

                res += board(solutions[i], color) + "\n";
            }

            if (solutionsToCount > solutionsToPrint) {
                res += "(" + format::countable(solutionsToCount - solutionsToPrint, "solution") + " not shown)\n";
            }
        }

        return res;
     }
}