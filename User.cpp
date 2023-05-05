#include "User.h"

User::User(string name) : username(name) {}

void User::setUsername(string name){
    username = name;
}

string User::getUsername(){
    return username;
}

void User::addActivity(string title){
    bool found = false;
    for(auto& A : activities){
        if(A.getTitle()==title) found = true;
    }

    if(!found){
        Activity newActivity(title);
        activities.push_back(newActivity);
    } else {
        cout << "Activity already exists.\n";
    }
}

void User::removeActivity(int index){
    activities.erase(activities.begin() + index - 1);
}

void User::viewActivities(){
    cout << "Activities :\n";
    for(int i = 0; i < activities.size(); i++){
        cout << i + 1 << ". " << activities[i].getTitle() << '\n';
    }
}

Activity User::getActivity(int index){
    return activities[index - 1];
}

int User::activitiesCount(){
    return (int)activities.size();
}