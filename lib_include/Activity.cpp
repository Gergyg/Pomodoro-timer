#include "DBManager.h"

Activity::Activity(string title, int id, string user) : title(title), id(id), user(user) {}

void Activity::setTitle(string title){
    this->title = title;
}

string Activity::getTitle(){
    return title;
}

void Activity::addTimer(int workTime, int shortBreakTime, int longBreakTime, int rounds, int roundsForLongBreak, string activity){
    int id = DBManager::getInstance()->getId();
    PomodoroTimer timer(workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak, activity, id, user);
    timers.push_back(id);
    DBManager::getInstance()->addTimer(id, timer);
}

void Activity::removeTimer(int index){
    timers.erase(timers.begin() + index - 1);
}

vector<vector<int>> Activity::viewTimers(){
    vector<vector<int>> res(timers.size());
    for(int i = 0; i < timers.size(); i++){
        res[i].push_back(DBManager::getInstance()->getTimerById(timers[i])->getWorkTime());
        res[i].push_back(DBManager::getInstance()->getTimerById(timers[i])->getShortBreakTime());
        res[i].push_back(DBManager::getInstance()->getTimerById(timers[i])->getLongBreakTime());
        res[i].push_back(DBManager::getInstance()->getTimerById(timers[i])->getRounds());
        res[i].push_back(DBManager::getInstance()->getTimerById(timers[i])->getRoundsForLongBreak());
    }
    return res;
}

int Activity::timersCount(){
    return (int)timers.size();
}

PomodoroTimer* Activity::getTimer(int index){
    return DBManager::getInstance()->getTimerById(timers[index - 1]);
}

tuple<string, string, int, vector<int>> Activity::getTuple(){
    return make_tuple(title, user, id, timers);
}