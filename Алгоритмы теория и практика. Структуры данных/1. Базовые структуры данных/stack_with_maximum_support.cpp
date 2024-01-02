#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string command;
    int comCount;
    int num;

    cin >> comCount;

    vector <pair<int,int>> arr;

    for (int i = 0; i < comCount; ++i) {

        cin >> command;

        if (command == "push") {
            cin >> num;

            if (arr.size() > 0) {

                if (arr[arr.size() - 1].first < num) {
                    arr.push_back(make_pair(num, 1));
                }
                else { ++arr[arr.size() - 1].second; }
            }

            else { arr.push_back(make_pair(num, 1)); }
        }

        else if (command == "pop") {

            if (arr[arr.size() - 1].second > 1) {
                --arr[arr.size() - 1].second;
            }
            else { arr.pop_back(); }

        }

        else if (command == "max") {

            cout << arr[arr.size() - 1].first << endl;

        }
    }

    return 0;
}