
#include "time_manager.hpp"

using namespace std::chrono;

TimeManager::TimeManager()
    : LastTime( steady_clock::now() ), Accumulator( 0.f ), Time( 0.f ),
      DeltaTime( 0.f ) {}

void TimeManager::update() {
    CurrTime = steady_clock::now();
    TimeTaken = CurrTime - LastTime;
    DeltaTime = static_cast< float >( TimeTaken.count() ) *
                steady_clock::period::num / steady_clock::period::den;
    LastTime = CurrTime;
    Accumulator += DeltaTime;
}

bool TimeManager::needsFixedUpdate() {
    const bool result = Accumulator >= FixedDt;

    if ( result ) {
        Accumulator -= FixedDt;
        Time += FixedDt;
    }

    return result;
}

const float TimeManager::getFixedDt() const { return FixedDt; }

const float TimeManager::getDeltaTime() const { return DeltaTime; }
