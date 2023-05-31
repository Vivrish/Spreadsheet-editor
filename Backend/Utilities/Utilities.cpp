#include "Utilities.h"

using namespace std;

size_t PairHash::operator()(const pair<int, int> & pair) const {
    return hash<int>()(pair.first) xor hash<int>()(pair.second);
}

template<typename Type>
void clearQueue(std::queue<Type> & input) {
    queue<Type>().swap(input);
}

template<typename Type>
void clearStack(std::stack<Type> & input) {
    while (not input.empty())
        input.pop();
}