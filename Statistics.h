#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Statistics{
private:
    map<string, int> workedTime;
    map<string, int> completedPomodoros;
    map<string, int> restTime;

    static Statistics* instance;

    Statistics() {}

public:
    int getWorkedTime(string act) {return workedTime[act]; }
    int getCompletedPomodoros(string act) {return completedPomodoros[act]; }
    int getRestTime(string act) {return restTime[act]; }
    void updateWorkedTime(string act, int time) { workedTime[act]+=time; }
    void updateCompletedPomodoros(string act) { completedPomodoros[act]++; }
    void updateRestTime(string act, int time) { restTime[act]+=time; }

    void showStats(){
        cout << "Your stats:\n";

        if(workedTime.empty()){
            cout << "No stats.\n";
            return;
        }

        for(auto& [title, cnt] : workedTime){
            cout << title << ":\n" 
            << "    Worked Time: " << cnt << '\n'
            << "    Completed Pomodoros: " << completedPomodoros[title] << '\n'
            << "    Rest Time: " << restTime[title] << '\n';
        }
    }

    static Statistics* getInstance() {
        if(instance == nullptr){
            instance = new Statistics();
        }
        return instance;
    }
};

