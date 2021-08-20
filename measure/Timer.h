#ifndef EV3_MEASURE_TIMER_H_
#define EV3_MEASURE_TIMER_H_

class Timer {
    public:
        Timer();
        void count();
        void reset();

    private:
        int time;
};

#endif