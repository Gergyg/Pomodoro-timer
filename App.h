#include "Authentication.h"

class App{
private:
    User user;
    Authentication auth;
    Activity activity;
    PomodoroTimer pomodoro;
    bool activityChosen = false;
    bool pomodoroChosen = false;

    void loggedIn();
    void createActivity();
    void chooseActivity();
    void activityRun();
    void createPomodoro();
    void choosePomodoro();

public:
    App() {};
    void run();
};

//Statistics* stats = Statistics::getInstance();