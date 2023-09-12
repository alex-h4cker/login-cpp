#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void clear_screen() {
    system("clear"); 
}

bool login(string username, string password) {
    ifstream file("users.txt");
    string line;
    
    while (getline(file, line)) {
        size_t pos = line.find(":");
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);
        
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    
    return false;
}

int main() {
    
    clear_screen();
    
    cout << "===================================================" << endl;
    cout << "||                                               ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "||                    Login                      ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "===================================================" << endl;
    string username, password;
    
    cout << "Enter your username: ";
    cin >> username;
    
    cout << "Enter your password: ";
    cin >> password;
    
    if (login(username, password)) {
        cout << "Logged in successfully!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }
    
    return 0;
}
