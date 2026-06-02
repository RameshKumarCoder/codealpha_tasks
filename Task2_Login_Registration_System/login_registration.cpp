#include <iostream>
#include <fstream>
using namespace std;

bool registerUser(string username, string password) {
    ofstream file(username + ".txt");
    if (!file) return false;

    file << username << endl;
    file << password << endl;
    file.close();
    return true;
}

bool loginUser(string username, string password) {
    ifstream file(username + ".txt");
    if (!file) return false;

    string u, p;
    getline(file, u);
    getline(file, p);

    return (u == username && p == password);
}

int main() {
    int choice;
    string username, password;

    cout << "1. Register\n2. Login\nChoose: ";
    cin >> choice;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (choice == 1) {
        if (registerUser(username, password))
            cout << "Registration successful!\n";
        else
            cout << "Error in registration!\n";
    }
    else if (choice == 2) {
        if (loginUser(username, password))
            cout << "Login successful!\n";
        else
            cout << "Invalid credentials!\n";
    }

    return 0;
}