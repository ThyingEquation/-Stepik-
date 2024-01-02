#include <iostream>
#include <vector>
#include <deque>

// useful reference:  https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

using namespace std;

int main() {

    int num;
    int winS;
    int count = 0;

    cin >> num;

    vector <int> arr(num);

    for (int i = 0; i < num; ++i) {
        cin >> arr[i];
    }

    cin >> winS;


    if (winS == 1) {

        for (int i = 0; i < num; ++i) {

            cout << arr[i] << " ";

        }

        return 0;

    }

    else if (winS == 0) { return 0; }


    deque <int> deq (winS);

    deq.push_back(0);

    for (int i = 0; i < winS; ++i) {

        while ((deq.size() > 0) && (arr[deq.back()] <= arr[i])) {

            deq.pop_back();

        }
       
        deq.push_back(i);
    }

    cout << arr[deq.front()] << " ";

    for (int i = winS; i < num; ++i) {

        if (deq.front() == count) {

            deq.pop_front();

        }

        while ((deq.size() > 0) && (arr[deq.back()] <= arr[i])) {
            deq.pop_back();
        }

        deq.push_back(i);
        ++count;
        cout << arr[deq.front()] << " ";
    }

    return 0;
}
