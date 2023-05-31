#ifndef POMODOROTIMER_H
#define POMODOROTIMER_H

#include "Statistics.h"

class PomodoroTimer{
private:
    string activity;
    string user;
    int id;
    int workTime;
    int shortBreakTime;
    int longBreakTime;
    int rounds;
    int roundsForLongBreak;
    int currentState;

public:
    PomodoroTimer() {};
    PomodoroTimer(int workTime, int shortBreakTime, int longBreakTime, int rounds, int roundsForLongBreak, string activity, int id, string user);
    void setWorkTime(int time);
    void setShortBreakTime(int time);
    void setLongBreakTime(int time);
    void setRounds(int count);
    void setRoundsForLongBreak(int count);
    int getWorkTime();
    int getShortBreakTime();
    int getLongBreakTime();
    int getRounds();
    int getRoundsForLongBreak();
    void startTimer();
    tuple<string, string, int, int, int, int, int, int> getTuple();
};

//Statistics* stats = Statistics::getInstance();


#endif // POMODOROTIMER_H
