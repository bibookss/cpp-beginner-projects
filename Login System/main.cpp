#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct User {
    string username;
    string password;
};

class System {
    private:
    User user;

    public:
    void logIn();
    bool userExist(User u);
    bool checkCredentials(User u);
    void signUp();
    void forgot();
};

void System::signUp() {
    User newUser;

    do{
        system("clear");
        cout << "SIGN-UP\n";
        cout << "Username: "; 
        cin >> newUser.username;
        cout << "Password: ";
        cin >> newUser.password;
    } while (userExist(newUser));

    ofstream Database;
    Database.open("Database.txt", ios::out | ios::app);
    Database << newUser.username << " " << newUser.password << endl;
    Database.close();
}

void System::logIn() {
    User User;
    do{
        system("clear");
        cout << "LOG-IN\n";
        cout << "Username: "; 
        cin >> User.username;
        cout << "Password: ";
        cin >> User.password;

    } while(!checkCredentials(User));
}

void System::forgot(){
    cout << "FORGOT PASSWORD\n";
    User u;
    cout << "Please enter your username to search for your account\n";
    cin >> u.username;

    if(userExist(u)){
        cout << "Enter your new password: " << endl;
        cin >> u.password;

        ifstream Database;
        ofstream temp;
        temp.open("temp.txt");
        Database.open("Database.txt", ios::in);

        string us, pa;
        while(Database >> us >> pa){
            if(!(us == u.username)){
                temp << us << " " << pa << endl;
            }
        }
        temp << u.username << " " << u.password << endl;

        temp.close();
        Database.close();
        remove("Database.txt");
        rename("temp.txt", "Database.txt");
    }
}

bool System::checkCredentials(User u) {
    ifstream Database;
    Database.open("Database.txt", ios::in);

    string us, pa;
    while(Database >> us >> pa){
        if(us == u.username && pa == u.password){
            cout << "You are now logged in.\n";
            Database.close();
            return true;
        }
    }
    cout << "Wrong credentials. Try again.\n";
    
    char c = 'a'; 
    while(c != 'A'){
        cout << "Press A to continue\n";
        cin >> c;
    }
    
    Database.close();
    return false;
}

bool System::userExist(User u) {
    ifstream Database;
    Database.open("Database.txt", ios::in);

    string us, pa;
    while(Database >> us >> pa){
        if(us == u.username){
            cout << "Username exists.\n";

            char c = 'a'; 
            while(c != 'A'){
                cout << "Press A to continue\n";
                cin >> c;
            }

            Database.close();
            return true;
        }
    }
    Database.close();
    return false;
}

int main(){
    do{
        System a;
        cout << "Welcome to Blank!\n";
        cout << "Pres 1 to log-in.\n";
        cout << "Pres 2 to sign-up.\n";
        cout << "Pres 3 to forget password.\n";
        cout << "Pres 4 to exit.\n\n";

        int opt; cin >> opt;
        switch(opt){
            case 1:
                a.logIn();
                break;
            case 2:
                a.signUp();
                break;
            case 3:
                a.forgot();
                break;
            case 4:
                return 0;
        }
    } while(true);

    return 0;
}