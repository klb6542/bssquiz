#pragma once
#include <raylib.h>
#include <stdexcept>
#include <thread>

class Timer {
    public:
        Timer(double seconds);

        template<typename Func, typename... Args>
        void WhenDone(const Func& func, Args&... args);
    private:
        double m_endTime;
        bool m_initiated{};
};

template <typename Func, typename... Args>
void Timer::WhenDone(const Func& func, Args&... args) {
    if (this->m_initiated)
        throw std::runtime_error("You may only call this method once!");

    this->m_initiated = true;
    this->m_endTime += GetTime();

    std::thread([func, args..., this]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(this->m_endTime * 1000)));
        func(args...);
    }).detach();
}
