#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class Activity;

class User{
private:
    string username;
    int id;
    vector<int> activities;

public:
    User() {};
    User(string name, int id);
    void setUsername(string name);
    void setActivities(vector<int>& act){activities = move(act);}
    string getUsername();
    bool addActivity(string activity);
    void removeActivity(int index);
    vector<string> viewActivities();
    Activity* getActivity(int index);
    int activitiesCount();
    tuple<int, string, vector<int>> getTuple();
};

#endif // USER_H
