#include "App.h"
using namespace std;


void App::run(){
    cout << "Welcome to the pomodoro timer app!\n\n";

    bool exit = false;

    while(!exit){
        cout << "\nWhat would you like to do?\n"
        << "1. Sign up\n"
        << "2. Log in\n"
        << "3. Exit\n";

        int choice;
        cin >> choice;
        if(choice == 1){
            auth.signup();
        } else if (choice == 2){
            auth.login();
            if(auth.isAuthenticated()){
                loggedIn();
            }
        } else if(choice == 3){
            exit = true;
        } else {
            cout << "Wrong choice.\n";
        }
    }
}

void App::loggedIn(){
    user = auth.getUser();
    cout << "Welcome, " << user.getUsername() << '\n';

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
            user.viewActivities();
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
            Statistics::getInstance()->showStats();
        } else {
            cout << "Wrong choice.\n";
        }
    }
}

void App::createActivity(){
    string act;
    cout << "Enter name of activity:\n";
    cin >> act;
    user.addActivity(act);
}

void App::chooseActivity(){
    int border = user.activitiesCount();
    cout << "Enter number of activity:\n";
    int index;
    cin >> index;
    if(index < 1 || index > border){
        cout << "Wrong index.\n";
    } else {
        activityChosen = true;
        activity = user.getActivity(index);
    }
}

void App::activityRun(){
    cout << "Activity - " << activity.getTitle() << '\n';

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
            activity.viewTimers();
        } else if (choice == 2){
            createPomodoro();
        } else if (choice == 3){
            choosePomodoro();
            if(pomodoroChosen){
                pomodoro.startTimer();
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

    PomodoroTimer timer(workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak, activity.getTitle());
    activity.addTimer(timer);
}

void App::choosePomodoro(){
    int border = activity.timersCount();
    cout << "Enter number of timer:\n";
    int index;
    cin >> index;
    if(index < 1 || index > border){
        cout << "Wrong index.\n";
    } else {
        pomodoroChosen = true;
        pomodoro = activity.getTimer(index);
    }
}