#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int countS = 0;
    int num = 0;
    string command = "";
    priority_queue<int> numbers;
    cin >> countS;

    while (countS != 0) {

        cin >> command; 

        if (command == "Insert") {
           cin >> num;
            numbers.push(num);
            command = "";
            num = 0;
            --countS;
        }

        else if (command == "ExtractMax") {
            cout << numbers.top() << endl;
            numbers.pop();
            command = "";
            --countS;
        }
       
    }
         
}