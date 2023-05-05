#include "Activity.h"

class User{
private:
    string username;
    vector<Activity> activities;

public:
    User() {};
    User(string name);
    void setUsername(string name);
    string getUsername();
    void addActivity(string activity);
    void removeActivity(int index);
    void viewActivities();
    Activity getActivity(int index);
    int activitiesCount();
};