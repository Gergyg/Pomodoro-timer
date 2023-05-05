#include "Statistics.h"

class PomodoroTimer{
private:
    string activity;
    int workTime;
    int shortBreakTime;
    int longBreakTime;
    int rounds;
    int roundsForLongBreak;
    int currentState;

public:
    PomodoroTimer() {};
    PomodoroTimer(int workTime, int shortBreakTime, int longBreakTime, int rounds, int roundsForLongBreak, string activity);
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
};

//Statistics* stats = Statistics::getInstance();

