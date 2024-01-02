#include <iostream>
#include <vector>

using namespace std;

int main() {

    int numCount;

    cin >> numCount;

    vector <int> nums(numCount);

    int score[11] = { 0, };

    for (int a = 0; a < numCount; a++) {
        cin >> nums[a];
    }

    for (int k = 0; k < numCount; k++) {

        score[nums[k]] += 1;

    }

    int i = 0;
    int j = 0;

    while (i != 12) {

        if (score[i] == 0) {
            i++;
        }
        else {

            for (int a = 0; a < score[i]; a++) {

                nums[j] = i;
                j++;

            }
            i++;
        }

    }


    for (int a = 0; a < numCount; a++) {
        cout << nums[a] << " ";
    }


    return 0;
}