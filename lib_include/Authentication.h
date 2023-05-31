#include <map>
#include <string>
using namespace std;

class User;

class Authentication{
private:
    map<string, string> passwords;
    map<string, int> users;
    bool isAuth = false;
    string currentUser;
public:
    Authentication() {};
    void signup(string username, string password);
    bool login(string username, string password);
    void logout();
    bool isAuthenticated();
    bool isExists(string username);
    User* getUser();
    void passwordsSet(map<string, string>& curr);
    void usersSet(map<string, int>& curr);
    map<string, string> passwordsGet() {return passwords;}
    map<string, int> usersGet() {return users;}
};