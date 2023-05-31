#ifndef STATISTICS_H
#define STATISTICS_H

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

    vector<map<string, map<string, int>>> getBase(){
        vector<map<string, map<string, int>>> tmp;
        tmp.push_back(workedTime);
        tmp.push_back(completedPomodoros);
        tmp.push_back(restTime);
        return tmp;
    }

    void setBase(vector<map<string, map<string, int>>> tmp){
        workedTime = tmp[0];
        completedPomodoros = tmp[1];
        restTime = tmp[2];
    }

    int getWorkedTime(string user, string act) {return workedTime[user][act]; }
    int getCompletedPomodoros(string user, string act) {return completedPomodoros[user][act]; }
    int getRestTime(string user, string act) {return restTime[user][act]; }
    void updateWorkedTime(string user, string act, int time) { workedTime[user][act]+=time; }
    void updateCompletedPomodoros(string user, string act) { completedPomodoros[user][act]++; }
    void updateRestTime(string user, string act, int time) { restTime[user][act]+=time; }

    vector<pair<string, vector<int>>> showStats(string user){
        vector<pair<string, vector<int>>> res;

        for(auto& pr : workedTime[user]){
            auto title = pr.first;
            auto cnt = pr.second;
            vector<int> tmp;
            tmp.push_back(cnt);
            tmp.push_back(completedPomodoros[user][title]);
            tmp.push_back(restTime[user][title]);

            auto pb = make_pair(title, tmp);
            res.push_back(pb);
        }

        return res;
    }

    static Statistics* getInstance() {
        if(instance == nullptr){
            instance = new Statistics();
        }
        return instance;
    }
};



#endif // STATISTICS_H
