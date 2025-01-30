
#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP
#pragma once

#include <chrono>

class TimeManager {
public:
    TimeManager();

    void update();
    bool needsFixedUpdate();

    const float getFixedDt() const;
    const float getDeltaTime() const;
private:
    std::chrono::steady_clock::time_point LastTime;
    std::chrono::steady_clock::time_point CurrTime;
    std::chrono::steady_clock::duration TimeTaken;
    float Accumulator;
    float Time;
    float DeltaTime;
    const float FixedDt = 0.02f;
};

#endif
