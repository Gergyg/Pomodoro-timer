#include "authentication.h"
#include "DBManager.h"

DBManager* DBManager::instance = nullptr;

bool Authentication::isExists(string username){
    return (passwords.find(username)!=passwords.end());
}

void Authentication::signup(string username, string password){
    passwords[username] = password;

    int id = DBManager::getInstance()->getId();
    User newUser(username, id);
    users[username] = id;
    DBManager::getInstance()->addUser(id, newUser);
}

bool Authentication::login(string username, string password){
    if(passwords.find(username) == passwords.end()){
        return false;
    }

    if(passwords[username] != password){
        return false;
    }

    currentUser = username;
    isAuth = true;
    return true;
}

void Authentication::logout(){
    currentUser = "";
    isAuth = false;
}

bool Authentication::isAuthenticated(){
    return isAuth;
}

User* Authentication::getUser(){
    if(!isAuth) throw runtime_error("Access error");
    return DBManager::getInstance()->getUserById(users[currentUser]);
}

void Authentication::passwordsSet(map<string, string>& curr){
    passwords = move(curr);
}

void Authentication::usersSet(map<string, int>& curr){
    users = move(curr);
}
