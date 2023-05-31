#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Statistics{
private:
    map<string, map<string, int>> workedTime;
    map<string, map<string, int>> completedPomodoros;
    map<string, map<string, int>> restTime;

    static Statistics* instance;

    Statistics() {}

public:
    Statistics(map<string, map<string, int>> workedTime,
                    map<string, map<string, int>> completedPomodoros,
                        map<string, map<string, int>> restTime) : 
                            workedTime(workedTime),
                            completedPomodoros(completedPomodoros),
                            restTime(restTime) {}

    int getWorkedTime(string user, string act) {return workedTime[user][act]; }
    int getCompletedPomodoros(string user, string act) {return completedPomodoros[user][act]; }
    int getRestTime(string user, string act) {return restTime[user][act]; }
    void updateWorkedTime(string user, string act, int time) { workedTime[user][act]+=time; }
    void updateCompletedPomodoros(string user, string act) { completedPomodoros[user][act]++; }
    void updateRestTime(string user, string act, int time) { restTime[user][act]+=time; }

    void showStats(string user){
        cout << "Your stats:\n";

        if(workedTime.empty()){
            cout << "No stats.\n";
            return;
        }

        for(auto& [title, cnt] : workedTime[user]){
            cout << title << ":\n" 
            << "    Worked Time: " << cnt << '\n'
            << "    Completed Pomodoros: " << completedPomodoros[user][title] << '\n'
            << "    Rest Time: " << restTime[user][title] << '\n';
        }
    }

    static Statistics* getInstance() {
        if(instance == nullptr){
            instance = new Statistics();
        }
        return instance;
    }
};

