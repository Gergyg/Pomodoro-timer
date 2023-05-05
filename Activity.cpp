#include "Activity.h"
Activity::Activity(string title) : title(title) {}

void Activity::setTitle(string title){
    this->title = title;
}

string Activity::getTitle(){
    return title;
}

void Activity::addTimer(PomodoroTimer timer){
    timers.push_back(timer);
}

void Activity::removeTimer(int index){
    timers.erase(timers.begin() + index - 1);
}

void Activity::viewTimers(){
    cout << "Timers(work time, short break time, long break time, rounds number, number of rounds for long break) :\n";
    for(int i = 0; i < timers.size(); i++){
        cout << i + 1 << ": "
        << timers[i].getWorkTime() << ", "
        << timers[i].getShortBreakTime() << ", "
        << timers[i].getLongBreakTime() << ", "
        << timers[i].getRounds() << ", "
        << timers[i].getRoundsForLongBreak() << ".\n";
    }
}

int Activity::timersCount(){
    return (int)timers.size();
}

PomodoroTimer Activity::getTimer(int index){
    return timers[index - 1];
}