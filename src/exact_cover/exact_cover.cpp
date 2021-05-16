#include "exact_cover.h"

#include "dlx.h"
#include "sat.h"

namespace exact_cover {
    std::vector<Solution> solve (const Problem& problem, int solutionLimit, Method method) {
        switch (method) {
        case Method::dlx:
            return dlx(problem, solutionLimit);
        case Method::sat:
            return sat(problem, solutionLimit);
        }
    }
}