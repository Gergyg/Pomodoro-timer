#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ExtraWindows/signupwindow.h"
#include "JsonSerializer/jsonserializer.h"
#include "ExtraWindows/loginwindow.h"
#include "Logic/DBManager.h"
#include "JsonSerializer/jsonserializer.h"
#include "Logic/Statistics.h"
#include "loggedinwindow.h"
#include "globals.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>

vector<tuple<int, string, vector<int>>> users_to_vec(){
    vector<tuple<int, string, vector<int>>> res;
    auto users = DBManager::getInstance()->usersGet();
    for(auto& pr:users){
        auto user = pr.second;
        res.push_back(user.getTuple());
    }
    return res;
}

vector<tuple<string, string, int, vector<int>>> activities_to_vec(){
    vector<tuple<string, string, int, vector<int>>> res;
    auto activities = DBManager::getInstance()->activitiesGet();
    for(auto& pr:activities){
        auto activity = pr.second;
        res.push_back(activity.getTuple());
    }
    return res;
}

vector<tuple<string, string, int, int, int, int, int, int>> timers_to_vec(){
    vector<tuple<string, string, int, int, int, int, int, int>> res;
    auto timers = DBManager::getInstance()->timersGet();
    for(auto& pr:timers){
        auto timer = pr.second;
        res.push_back(timer.getTuple());
    }
    return res;
}

void serialize(){
    auto passwords = auth->passwordsGet();
    auto authusers = auth->usersGet();
    serializePasswords(passwords, authusers, "auth.json");

    auto stats = Statistics::getInstance()->getBase();
    serializeStats(stats, "stats.json");

    serializeUsers(users_to_vec(), "users.json");
    serializeActivities(activities_to_vec(), "activities.json");
    serializeTimers(timers_to_vec(), "timers.json");
}

void deserialize(){
    int mxid = 0;
    auto pr = deserializePasswords("auth.json");
    auto passwords = pr.first;
    auto authusers = pr.second;
    auth->passwordsSet(passwords);
    auth->usersSet(authusers);

    auto stats = deserializeStats("stats.json");
    Statistics::getInstance()->setBase(stats);

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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deserialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    signupwindow window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    loginwindow window;
    window.setModal(true);
    window.exec();
    if(isLogged){
        hide();
        loggedinwindow nxt(this);
        nxt.setModal(true);
        nxt.exec();
    }
}

void MainWindow::closing()
{
    serialize();
}



void MainWindow::on_pushButton_5_clicked()
{
    close();
}

