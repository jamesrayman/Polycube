#include "stopwatch.h"

#include <chrono>

long long Stopwatch::currentTime () {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


Stopwatch::Stopwatch () {
    start();
}

void Stopwatch::start () {
    startTime = currentTime();
    stopped = false;
}

void Stopwatch::stop () {
    stopTime = currentTime();
    stopped = true;
}

long long Stopwatch::time () const {
    if (stopped) {
        return stopTime - startTime;
    }
    else {
        return currentTime() - startTime;
    }
}
