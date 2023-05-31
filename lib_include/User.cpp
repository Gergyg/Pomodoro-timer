#include "DBManager.h"

User::User(string name, int id) : username(name), id(id) {}

void User::setUsername(string name){
    username = name;
}

string User::getUsername(){
    return username;
}

bool User::addActivity(string title){
    bool found = false;
    for(auto& A : activities){
        if(DBManager::getInstance()->getActivityById(A)->getTitle()==title) found = true;
    }

    if(!found){
        int id = DBManager::getInstance()->getId();
        Activity newActivity(title, id, username);
        activities.push_back(id);
        DBManager::getInstance()->addActivity(id, newActivity);
        return true;
    } else {
        return false;
    }
}

void User::removeActivity(int index){
    activities.erase(activities.begin() + index - 1);
}

vector<string> User::viewActivities(){
    vector<string> res;
    for(int i = 0; i < activities.size(); i++){
        res.push_back(DBManager::getInstance()->getActivityById(activities[i])->getTitle());
    }
    return res;
}

Activity* User::getActivity(int index){
    return DBManager::getInstance()->getActivityById(activities[index - 1]);
}

int User::activitiesCount(){
    return (int)activities.size();
}

tuple<int, string, vector<int>> User::getTuple(){
    return make_tuple(id, username, activities);
}