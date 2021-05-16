#pragma once

class Stopwatch {
private:
    long long startTime;
    long long stopTime;
    bool stopped;

    static long long currentTime ();
public:
    Stopwatch ();

    void start ();
    void stop ();
    long long time () const;
};
