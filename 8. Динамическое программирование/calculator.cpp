#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[3000000] = { 0, };

int main() {

    int num; 
    cin >> num;


    for (int i = 1; i < num; ++i) {

        if (3*i <= num) {
            arr[3 * i] = (((1 + arr[i]) < arr[3 * i]) || arr[3 * i] == 0) ? 1 + arr[i] : arr[3 * i];
        }

        if (2 * i <= num) {
            arr[2 * i] = (((1 + arr[i]) < arr[2 * i]) || arr[2 * i] == 0) ? 1 + arr[i] : arr[2 * i];
        }

        if (1 + i <= num) {
            arr[1 + i] = (((1 + arr[i]) < arr[1 + i]) || arr[1 + i] == 0) ? 1 + arr[i] : arr[1 + i];
        }

    }

       cout << arr[num] << endl;

        int x = arr[num];
        vector <int> res(x+1);
        res[x] = num;
        --x;

        while (num != 1) {

            if ((arr[num / 3] == x) && (num % 3 == 0) ) {
                num = num / 3;
                
                res[x] = num;
                --x;

            }

            else if ((arr[num / 2] == x) && (num % 2 == 0)) {
                num = num / 2;
               
                res[x] = num;
                --x;
            }

            else if (arr[num - 1] == x) {
                num = num - 1;
               
                res[x] = num;
                --x;
            }
            else {
                --num;
            }
        }

        for (int i = 0; i < res.size(); i++) {

            cout << res[i] << " ";
        }

    return 0;
}