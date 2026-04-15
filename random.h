#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <mutex>

class Random {
public:
    static int get(int min, int max) {
        static Random instance;
        std::lock_guard<std::mutex> lock(instance.mutex_);
        std::uniform_int_distribution<> dis(min, max);
        return dis(instance.gen_);
    }

private:
    Random() : gen_(std::random_device{}()) {}
    std::mt19937 gen_;
    std::mutex mutex_;
};

inline int random(int min, int max) {
    thread_local static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

#endif