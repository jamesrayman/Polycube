#pragma once

#include <vector>

namespace exact_cover {
    enum class Method {
        dlx,
        sat
    };

    using Problem = std::vector<std::vector<char>>;
    using Solution = std::vector<int>;

    std::vector<Solution> solve (const Problem&, int, Method);
}

