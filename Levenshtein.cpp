
#include "Levenshtein.hpp"
#include <algorithm>
#include <vector>

template<typename L>
typename T::size_type Levenshtein(const L &source,
                                          const L &target) {
    if (source.size() > target.size()) {
        return Levenshtein(target, source);
    }

    using LSizeType = typename L::size_type;
    const LSizeType min_size = source.size(), max_size = target.size();
    std::vector<LSizeType> lev_dist(min_size + 1);

    for (LSizeType i = 0; i <= min_size; ++i) {
        lev_dist[i] = i;
    }

    for (LSizeType j = 1; j <= max_size; ++j) {
        LSizeType diagonal = lev_dist[0],
        diagonal_save;
        ++lev_dist[0];

        for (LSizeType i = 1; i <= min_size; ++i) {
            diagonal_save = lev_dist[i];
            if (source[i - 1] == target[j - 1]) {
                lev_dist[i] = diagonal;
            } else {
                lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), diagonal) + 1;
            }
            diagonal = diagonal_save;
        }
    }

    return lev_dist[min_size];
}
