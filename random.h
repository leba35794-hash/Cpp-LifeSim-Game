#ifndef RANDOM_H
#define RANDOM_H

#include <random>

inline int random(int min, int max) {
    thread_local static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

inline double random(double min, double max) {
    thread_local static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

inline bool randomBool() {
    thread_local static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(0, 1);
    return dis(gen) == 1;
}

#endif
