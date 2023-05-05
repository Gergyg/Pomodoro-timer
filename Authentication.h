#include "User.h"

class Authentication{
private:
    map<string, string> passwords;
    map<string, User> users;
    bool isAuth = false;
    string currentUser;
public:
    Authentication() {};
    void signup();
    void login();
    void logout();
    bool isAuthenticated();
    User getUser();
};