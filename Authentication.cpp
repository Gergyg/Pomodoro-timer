#include "Authentication.h"

void Authentication::signup(){
    string username;
    cout << "Enter username:\n";
    cin >> username;
    if(passwords.find(username) != passwords.end()){
        cout << "This user already exists.\n";
        return;
    }

    string password1, password2;
    cout << "Enter password:\n";
    cin >> password1;
    cout << "Confirm password:\n";
    cin >> password2;
    if(password1 != password2){
        cout << "Passwords don't match\n";
        return;
    }
    cout << "User created.\n";
    passwords[username] = password1;

    User newUser(username);
    users[username] = newUser;
}

void Authentication::login(){
    string username;
    cout << "Enter username:\n";
    cin >> username;
    if(passwords.find(username) == passwords.end()){
        cout << "This user does not exist.\n";
        return;
    }

    string password;
    cout << "Enter password:\n";
    cin >> password;

    if(passwords[username] != password){
        cout << "Wrong password.\n";
        return;
    }

    currentUser = username;
    isAuth = true;
}

void Authentication::logout(){
    currentUser = "";
    isAuth = false;
}

bool Authentication::isAuthenticated(){
    return isAuth;
}

User Authentication::getUser(){
    if(!isAuth) throw runtime_error("Access error");
    return users[currentUser];
}