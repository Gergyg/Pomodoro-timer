#include "Authentication.h"
#include "DBManager.h"

class App{
private:
    User* user;
    Authentication* auth;
    Activity* activity;
    PomodoroTimer* pomodoro;
    bool activityChosen = false;
    bool pomodoroChosen = false;

    void signUp();
    void logIn();
    void loggedIn();
    void createActivity();
    void chooseActivity();
    void activityRun();
    void createPomodoro();
    void choosePomodoro();

    void serialize();
    void deserialize();

public:
    App() {
        auth = new Authentication();
    };
    ~App() {
        delete auth;
    }
    void run();
};

//Statistics* stats = Statistics::getInstance();