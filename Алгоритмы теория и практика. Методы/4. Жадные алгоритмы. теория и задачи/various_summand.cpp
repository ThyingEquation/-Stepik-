#include <iostream>
#include <vector>

using namespace std;


int main(void) {

    int number = 0;
    int result = 0;

    int a = 1;
    int x = 0;

    vector <int> arr;

    cin >> number;

    while (x != 1) {
       
        result = result + a;

            if (result > number) {
                arr.pop_back();
                result = result - a;
                --a;
                result = result - a;
                result = number - result;
                arr.push_back(result);
                x = 1;
            }

            else { arr.push_back(a); }

            ++a;
    }
    
    cout << arr.size() << endl; 

    for (int z = 0; z < arr.size(); z++) {
        cout << arr[z] << " ";
    }

}