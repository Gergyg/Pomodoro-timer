#include "App.h"
using namespace std;
#include "libs/jsonserializer.hpp"

void App::run(){
    cout << "Welcome to the pomodoro timer app!\n\n";
    deserialize();
    bool exit = false;

    while(!exit){
        cout << "\nWhat would you like to do?\n"
        << "1. Sign up\n"
        << "2. Log in\n"
        << "3. Exit\n";

        int choice;
        cin >> choice;
        if(choice == 1){
            signUp();
        } else if (choice == 2){
            logIn();
            if(auth->isAuthenticated()){
                loggedIn();
            }
        } else if(choice == 3){
            exit = true;
        } else {
            cout << "Wrong choice.\n";
        }
    }
    serialize();
}

void App::signUp(){
    string username;
    cout << "Enter username:\n";
    cin >> username;
    if(auth->isExists(username)){
        cout << "This user already exists.\n";
        return;
    }

    string password1, password2;
    cout << "Enter password:\n";
    cin >> password1;
    cout << "Confirm password:\n";
    cin >> password2;
    if(password1 != password2){
        cout << "Passwords don't match\n";
        return;
    }
    cout << "User created.\n";
    auth->signup(username, password1);
}

void App::logIn(){
    
    string username;
    cout << "Enter username:\n";
    cin >> username;

    string password;
    cout << "Enter password:\n";
    cin >> password;

    bool res = auth->login(username, password);
    if(!res){
        cout << "Wrong password or username.\n";
    }
}

void App::loggedIn(){
    user = auth->getUser();
    cout << "Welcome, " << user->getUsername() << '\n';

    activityChosen = false;
    bool exit = false;
    while(!exit){
        cout << "\nWhat would you like to do?\n"
        << "1. Show activities\n"
        << "2. Create activity\n"
        << "3. Choose activity\n"
        << "4. Log out\n"
        << "5. View statistics\n";

        int choice;
        cin >> choice;
        if(choice == 1){
            vector<string> view = user->viewActivities();
            cout << "Activities :\n";
            for(int i = 0; i < view.size(); i++){
                cout << i + 1 << ". " << view[i] << '\n';
            }
        } else if (choice == 2){
            createActivity();
        } else if (choice == 3){
            chooseActivity();
            if(activityChosen){
                activityRun();
            }
        } else if (choice == 4){
            exit = true;
        } else if (choice == 5){
            Statistics::getInstance()->showStats(user->getUsername());
        } else {
            cout << "Wrong choice.\n";
        }
    }
}

void App::createActivity(){
    string act;
    cout << "Enter name of activity:\n";
    cin >> act;
    bool res = user->addActivity(act);
    if(!res){
        cout << "Activity already exists.\n";
    }
}

void App::chooseActivity(){
    int border = user->activitiesCount();
    cout << "Enter number of activity:\n";
    int index;
    cin >> index;
    if(index < 1 || index > border){
        cout << "Wrong index.\n";
    } else {
        activityChosen = true;
        activity = user->getActivity(index);
    }
}

void App::activityRun(){
    cout << "Activity - " << activity->getTitle() << '\n';

    pomodoroChosen = false;
    bool exit = false;
    while(!exit){
        cout << "\nWhat would you like to do?\n"
        << "1. Show pomodoros\n"
        << "2. Create pomodoro\n"
        << "3. Choose and run pomodoro\n"
        << "4. Exit from this activity\n";

        int choice;
        cin>>choice;
        if(choice == 1){
            vector<vector<int>> view = activity->viewTimers();
            cout << "Timers(work time, short break time, long break time, rounds number, number of rounds for long break) :\n";
            for(int i = 0; i<view.size(); i++){
                cout << i + 1 << ": ";
                for(int j = 0; j<5; j++){
                    cout << view[i][j];
                    if(j != 5) cout <<", ";
                    else cout << ".\n";
                }
            }
        } else if (choice == 2){
            createPomodoro();
        } else if (choice == 3){
            choosePomodoro();
            if(pomodoroChosen){
                (*pomodoro).startTimer();
            }
        } else if (choice == 4){
            exit = true;
        } else {
            cout << "Wrong choice.\n";
        }
    }
}

void App::createPomodoro(){
    int workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak;
    cout << "Enter work time:\n";
    cin >> workTime;
    cout << "Enter short break time:\n";
    cin >> shortBreakTime;
    cout << "Enter long break time:\n";
    cin >> longBreakTime;
    cout << "Enter rounds:\n";
    cin >> rounds;
    cout << "Enter rounds for long break:\n";
    cin >> roundsForLongBreak;

    activity->addTimer(workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak, activity->getTitle());
}

void App::choosePomodoro(){
    int border = activity->timersCount();
    cout << "Enter number of timer:\n";
    int index;
    cin >> index;
    if(index < 1 || index > border){
        cout << "Wrong index.\n";
    } else {
        pomodoroChosen = true;
        pomodoro = activity->getTimer(index);
    }
}

vector<tuple<int, string, vector<int>>> users_to_vec(){
    vector<tuple<int, string, vector<int>>> res;
    auto users = DBManager::getInstance()->usersGet();
    for(auto& [id, user]:users){
        res.push_back(user.getTuple());
    }
    return res;
}

vector<tuple<string, string, int, vector<int>>> activities_to_vec(){
    vector<tuple<string, string, int, vector<int>>> res;
    auto activities = DBManager::getInstance()->activitiesGet();
    for(auto& [id, activity]:activities){
        res.push_back(activity.getTuple());
    }
    return res;
}

vector<tuple<string, string, int, int, int, int, int, int>> timers_to_vec(){
    vector<tuple<string, string, int, int, int, int, int, int>> res;
    auto timers = DBManager::getInstance()->timersGet();
    for(auto& [id, timer]:timers){
        res.push_back(timer.getTuple());
    }
    return res;
}

void App::serialize(){
    auto passwords = auth->passwordsGet();
    auto authusers = auth->usersGet();
    serializePasswords(passwords, authusers, "auth.json");
    serializeUsers(users_to_vec(), "users.json");
    serializeActivities(activities_to_vec(), "activities.json");
    serializeTimers(timers_to_vec(), "timers.json");
}


void App::deserialize(){
    int mxid = 0;
    auto pr = deserializePasswords("auth.json");
    auto passwords = pr.first;
    auto authusers = pr.second;
    auth->passwordsSet(passwords);
    auth->usersSet(authusers);

    auto users = deserializeUsers("users.json");
    unordered_map<int, User> tmpUsers;
    for(auto& tup : users){
        int id = get<0>(tup);
        string username = get<1>(tup);
        auto activities = get<2>(tup);
        mxid = max(mxid, id);
        User nw(username, id);
        nw.setActivities(activities);
        tmpUsers[id] = nw;
    }
    DBManager::getInstance()->usersSet(tmpUsers);

    auto activities = deserializeActivities("activities.json");
    unordered_map<int, Activity> tmpActivities;
    for(auto& tup : activities){
        int id = get<2>(tup);
        string username = get<1>(tup);
        string title = get<0>(tup);
        auto timers = get<3>(tup);
        mxid = max(mxid, id);
        Activity nw(title, id, username);
        nw.setTimers(timers);
        tmpActivities[id] = nw;
    }
    DBManager::getInstance()->activitiesSet(tmpActivities);

    auto timers = deserializeTimers("timers.json");
    unordered_map<int, PomodoroTimer> tmpTimers;
    for(auto& tup : timers){
        int id = get<2>(tup);
        string username = get<1>(tup);
        string activity = get<0>(tup);
        int workTime = get<3>(tup);
        int shortBreakTime = get<4>(tup);
        int longBreakTime = get<5>(tup);
        int rounds = get<6>(tup);
        int roundsForLongBreak = get<7>(tup);
        mxid = max(mxid, id);
        PomodoroTimer nw(workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak, activity, id, username);
        tmpTimers[id] = nw;
    }
    DBManager::getInstance()->timersSet(tmpTimers);
    
    DBManager::getInstance()->setId(mxid);

}