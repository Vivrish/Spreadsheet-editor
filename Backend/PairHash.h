#ifndef SEMESTRALWORK_PAIRHASH_H
#define SEMESTRALWORK_PAIRHASH_H
#include <unordered_map>

struct PairHash {
    std::size_t operator () (const std::pair<int, int> & pair) const {
        return std::hash<int>()(pair.first) xor std::hash<int>()(pair.second);
    }
};
#endif //SEMESTRALWORK_PAIRHASH_H
