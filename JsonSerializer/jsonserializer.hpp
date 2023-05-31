#ifndef JSONSERIALIZER_HPP
#define JSONSERIALIZER_HPP

#include <string>
#include <tuple>
#include <vector>
#include <map>
using namespace std;

#if defined(__NT__)|| defined(_MSC_VER)|| defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(__WIN32__) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(_WIN62_) || defined(__WIN64) || defined(__WIN64__)
#define JSONSERIALIZER_EXPORT __declspec(dllexport)
#define JSONSERIALIZER_IMPORT __declspec(dllimport)
#endif


void JSONSERIALIZER_EXPORT serializePasswords(map<string, string> passwords, map<string, int> users, string file_name);

void JSONSERIALIZER_EXPORT serializeUsers(vector<tuple<int, string, vector<int>>> in_vec, string file_name);

void JSONSERIALIZER_EXPORT serializeActivities(vector<tuple<string, string, int, vector<int>>> in_vec, string file_name);

void JSONSERIALIZER_EXPORT serializeTimers(vector<tuple<string, string, int, int,
                                                int, int, int, int>> in_vec, string file_name);

pair<map<string, string>, map<string, int>> JSONSERIALIZER_EXPORT deserializePasswords(string file_name);

vector<tuple<int, string, vector<int>>> JSONSERIALIZER_EXPORT deserializeUsers(string file_name);

vector<tuple<string, string, int, vector<int>>> JSONSERIALIZER_EXPORT deserializeActivities(string file_name);

vector<tuple<string, string, int, int, int, int, int, int>> JSONSERIALIZER_EXPORT deserializeTimers(string file_name);


#endif // JSONSERIALIZER_H