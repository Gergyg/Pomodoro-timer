#include "PomodoroTimer.h"
using namespace std;
class Activity{
private:
    string title;
    vector<PomodoroTimer> timers;

public:
    Activity() {};
    Activity(string title);
    void setTitle(string title);
    string getTitle();
    void addTimer(PomodoroTimer timer);
    void removeTimer(int index);
    void viewTimers();
    PomodoroTimer getTimer(int index);
    int timersCount();
};