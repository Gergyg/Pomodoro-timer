#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <vector>
using namespace std;

class PomodoroTimer;

class Activity{
private:
    string title;
    string user;
    int id;
    vector<int> timers;

public:
    Activity() {};
    Activity(string title, int id, string user);
    void setTitle(string title);
    void setTimers(vector<int>& tim) {timers = move(tim);}
    string getTitle();
    void addTimer(int workTime, int shortBreakTime, int longBreakTime, int rounds, int roundsForLongBreak, string activity);
    void removeTimer(int index);
    vector<vector<int>> viewTimers();
    PomodoroTimer* getTimer(int index);
    int timersCount();
    tuple<string, string, int, vector<int>> getTuple();
};

#endif // ACTIVITY_H
