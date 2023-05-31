#include "jsonserializer.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>

void serializePasswords(map<string, string> passwords, map<string, int> users, string file_name){
    nlohmann::json j_tmp, j_res;
    vector<nlohmann::json> j_vec(1);
    j_tmp["passwords"] = passwords;
    j_tmp["users"] = users;
    j_vec[0] = j_tmp;

    ofstream out(file_name);
    out <<  setw(2) << j_vec;
    out.close();
}

void serializeUsers(vector<tuple<int, string, vector<int>>> in_vec, string file_name){
    nlohmann::json j_tmp, j_res;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {

        j_tmp["id"] = std::get<0>(in_vec[i]);
        j_tmp["username"] = std::get<1>(in_vec[i]);
        j_tmp["activities"] = std::get<2>(in_vec[i]);

        j_vec[i] = j_tmp;
    }

    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}

void serializeActivities(vector<tuple<string, string, int, vector<int>>> in_vec, string file_name){
    nlohmann::json j_tmp, j_res;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {

        j_tmp["title"] = std::get<0>(in_vec[i]);
        j_tmp["user"] = std::get<1>(in_vec[i]);
        j_tmp["id"] = std::get<2>(in_vec[i]);
        j_tmp["timers"] = std::get<3>(in_vec[i]);

        j_vec[i] = j_tmp;
    }

    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}



void serializeTimers(vector<tuple<string, string, int, int,
                                                int, int, int, int>> in_vec, string file_name){
    nlohmann::json j_tmp, j_res;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {

        j_tmp["activity"] = std::get<0>(in_vec[i]);
        j_tmp["user"] = std::get<1>(in_vec[i]);
        j_tmp["id"] = std::get<2>(in_vec[i]);
        j_tmp["workTime"] = std::get<3>(in_vec[i]);
        j_tmp["shortBreakTime"] = std::get<4>(in_vec[i]);
        j_tmp["longBreakTime"] = std::get<5>(in_vec[i]);
        j_tmp["rounds"] = std::get<6>(in_vec[i]);
        j_tmp["roundsForLongBreak"] = std::get<7>(in_vec[i]);

        j_vec[i] = j_tmp;
    }

    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}

pair<map<string, string>, map<string, int>> deserializePasswords(string file_name){
    nlohmann::json j;
    std::ifstream in(file_name);

    in >> j;
    in.close();

    for (auto x:j) {

        map<string, string> passwords = x["passwords"];
        map<string, int> users = x["users"];

        auto tmp = make_pair(passwords, users);

        return tmp;
    }
    pair<map<string, string>, map<string, int>> def;
    return def;
}

vector<tuple<int, string, vector<int>>> deserializeUsers(string file_name){
    nlohmann::json j;
    std::ifstream in(file_name);
    vector<tuple<int, string, vector<int>>> out_vec;


    in >> j;
    in.close();

    for (auto x:j) {

        int id = x["id"];
        string username = x["username"];
        vector<int> activities = x["activities"];

        auto tmp = std::make_tuple(id, username, activities);

        out_vec.push_back(tmp);
    }

    return out_vec;
}

vector<tuple<string, string, int, vector<int>>> deserializeActivities(string file_name){

    nlohmann::json j;
    std::ifstream in(file_name);
    vector<tuple<string, string, int, vector<int>>> out_vec;


    in >> j;
    in.close();

    for (auto x:j) {
        
        string title = x["title"];
        string user = x["user"];
        int id = x["id"];
        vector<int> timers = x["timers"];

        auto tmp = std::make_tuple(title, user, id, timers);

        out_vec.push_back(tmp);
    }

    return out_vec;
}

vector<tuple<string, string, int, int, int, int, int, int>> deserializeTimers(string file_name){

    nlohmann::json j;
    std::ifstream in(file_name);
    vector<tuple<string, string, int, int, int, int, int, int>> out_vec;


    in >> j;
    in.close();

    for (auto x:j) {
        
        string activity = x["activity"];
        string user = x["user"];
        int id = x["id"];
        int workTime = x["workTime"];
        int shortBreakTime = x["shortBreakTime"];
        int longBreakTime = x["longBreakTime"];
        int rounds = x["rounds"];
        int roundsForLongBreak = x["roundsForLongBreak"];

        auto tmp = std::make_tuple(activity, user, id, workTime, shortBreakTime, longBreakTime, rounds, roundsForLongBreak);

        out_vec.push_back(tmp);
    }

    return out_vec;
}