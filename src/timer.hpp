#pragma once
#include <raylib.h>
#include <thread>
#include <utility>

class Timer {
    public:
        template<typename Func, typename... Args>
        void Start(double seconds, const Func& func, Args&&... args);
};

template <typename Func, typename... Args>
void Timer::Start(double seconds, const Func& func, Args&&... args) {
    std::thread([seconds, func, args..., this]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(seconds * 1000)));
        func(std::forward<Args>(args)...);
    }).detach();
}
