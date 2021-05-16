#include "sat.h"

#include <vector>
#include <string>
#include <z3++.h>

namespace exact_cover {
    std::vector<Solution> sat (const Problem& problem, int solutionLimit) {
        z3::context context;
        z3::solver solver(context);

        z3::expr_vector x(context);

        for (int i = 0; i < problem.size(); i++) {
            std::string varName = "x" + std::to_string(i);
            x.push_back(context.bool_const(varName.c_str())); // x[i] iff the i-th candidate is taken
        }

        long long z = 0;

        for (int j = 0; j < problem[0].size(); j++) {
            z3::expr colSum(context);
            colSum = context.bool_val(false);

            for (int i = 0; i < problem.size(); i++) {
                if (problem[i][j]) {
                    colSum = colSum || x[i];

                    for (int k = i+1; k < problem.size(); k++) {
                        if (problem[k][j]) {
                            solver.add(!x[i] || !x[k]);
                            z++;
                        }
                    }
                }
            }

            colSum = colSum.simplify();

            solver.add(colSum);
        }

        std::cout << z << std::endl;

        switch (solver.check()) {
        case z3::sat: {
            Solution solution;
            z3::model model = solver.get_model();

            for (int i = 0; i < problem.size(); i++) {
                if (model.eval(x[i]).is_true()) {
                    solution.push_back(i);
                }
            }
            return std::vector<Solution> { solution };
        }
        default:
            return std::vector<Solution>();
        }
    }
}
