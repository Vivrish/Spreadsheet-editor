#ifndef SEMESTRALWORK_UTILITIES_H
#define SEMESTRALWORK_UTILITIES_H
#include <unordered_map>
#include <stack>
#include <queue>

struct PairHash {
    std::size_t operator () (const std::pair<int, int> & pair) const;
};


template<typename Type>
void clearStack(std::stack<Type> & input);

template<typename Type>
void clearQueue(std::queue<Type> & input);


#endif //SEMESTRALWORK_UTILITIES_H
