#include "adhoc.h"

#include <iostream>
#include <sstream>

#include "puzzle.h"
#include "read.h"
#include "parse.h"

int z = 0;

std::unordered_set<std::string> visited;
auto polycubeList = parse::import("./dat/41.cubes", visited);
Board unconstrained = parse::board("5 5 4"), constrained = parse::board("5 5 4 1");

struct Bag {
    std::string fixed;
    std::vector<std::string> variable;
    int k;

    Bag (const std::string& f, const::std::string& v, int k) : fixed(f), k(k) {
        std::stringstream stream (v);
        std::string word;

        while (stream >> word) {
            variable.push_back(word);
        }
    }
    
    void solve () {
        solve(fixed, 0, 0);
    }

    void solve (std::string& spec, int i, int j) {
        if (j == k) {
            z++;
            std::cout << "\r" << z;

            Puzzle puzzle (constrained, parse::polycubeList(spec, polycubeList));
            puzzle.initialize();
            auto solutions = puzzle.solve(1);

            if (solutions.size() == 0) {
                std::cout << "\n" << spec << "\n";
                puzzle = Puzzle(unconstrained, parse::polycubeList(spec, polycubeList));
                puzzle.initialize();
                solutions = puzzle.solve(1);

                if (solutions.size() == 0) {
                    throw "There is no solution";
                }
            }

            return;
        }
        for (; i <= variable.size() - (k-j); i++) {
            spec += " " + variable[i];
            
            solve(spec, i+1, j+1);
            
            for (int a = 0; a < variable[i].size() + 1; a++) {
                spec.pop_back();
            }
        }
    }
};

Bag easy ("3V 4I 4T 4L 4Z 4O 4Y 4IV 4VI", "5I 5P 5N 5F 5T 5U 5V 5W 5X 5Y 5Z 5L 5QQ 5JL 5LV 5JV 5VV 5VZ 5SV 5JJ 5LL 5TI 5TL 5TJ 5TT 5ZZ 5SS 5ZV 5VS", 13); 

int main () {
    easy.solve();

    std::cout << z << "\n";

    return 0;
}
