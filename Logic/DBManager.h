#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <unordered_map>
#include "user.h"
#include "activity.h"
#include "pomodorotimer.h"

class DBManager{
private:
    unordered_map<int, User> users;
    unordered_map<int, Activity> activities;
    unordered_map<int, PomodoroTimer> timers;
    int mx_id = 0;

    static DBManager* instance;

public:
    void setId(int mx){
        mx_id = mx;
    }

    int getId(){
        mx_id++;
        return mx_id;
    }

    void addUser(int id, User& user){
        users[id] = user;
    }

    void addActivity(int id, Activity& activity){
        activities[id] = activity;
    }

    void addTimer(int id, PomodoroTimer& timer){
        timers[id] = timer;
    }

    User* getUserById(int id){
        return &(users[id]);
    }

    Activity* getActivityById(int id){
        return &(activities[id]);
    }

    PomodoroTimer* getTimerById(int id){
        return &(timers[id]);
    }

    void usersSet(unordered_map<int, User>& curr){
        users = move(curr);
    }

    void activitiesSet(unordered_map<int, Activity>& curr){
        activities = move(curr);
    }

    void timersSet(unordered_map<int, PomodoroTimer>& curr){
        timers = move(curr);
    }

    unordered_map<int, User> usersGet() {return users;}
    unordered_map<int, Activity> activitiesGet() {return activities;}
    unordered_map<int, PomodoroTimer> timersGet() {return timers;}

    static DBManager* getInstance() {
        if(instance == nullptr){
            instance = new DBManager();
        }
        return instance;
    }
};

#endif // DBMANAGER_H
