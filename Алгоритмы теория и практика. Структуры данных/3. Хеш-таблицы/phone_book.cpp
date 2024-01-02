#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {

    unordered_map <int, string> TB;

    int commandsCount = 0;
    string command = "";
    int number = 0;
    string name = "";

    cin >> commandsCount;

    for (int i = 0; i < commandsCount; ++i) {

        cin >> command;
        cin >> number;

        if (command == "add") {
            cin >> name;
            TB [number] = name;
        }

        if (command == "find") {
            if (TB.find(number) == TB.end()) {
                cout << "not found" << endl;
            }
            else {
                cout << TB[number] << endl;
            }
        }

        if (command == "del") {
            if (TB.find(number) == TB.end()) {
            }
            else {
                TB.erase(number);
            }
        }

    }

    return 0;
}