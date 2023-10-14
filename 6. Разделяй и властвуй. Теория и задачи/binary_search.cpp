#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int arrSize;
    int operationsNum;

    cin >> arrSize;

    vector <int> arr(arrSize);

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cin >> operationsNum;

    vector <int> arrNum(operationsNum);

    vector <int> result(operationsNum);

    for (int i = 0; i < operationsNum; i++) {
        cin >> arrNum[i];
    }

    for (int i = 0; i < operationsNum; i++) {

        int q = 1;
        int newStart = 0;
        int newEnd = arrSize - 1;
        int nArrSize;

        if (((arrSize - 1) % 2) == 0) {
            nArrSize = (arrSize - 1) / 2;
        }


        else {

            if (arr[(((arrSize - 1) / 2) + 1)] == arrNum[i]) {

                result[i] = (((arrSize - 1) / 2) + 1) + 1;

                q = 0;
            }

            else if (arr[(((arrSize - 1) / 2))] == arrNum[i]) {

                result[i] = (((arrSize - 1) / 2)) + 1;

                q = 0;
            }

            else {
                nArrSize = (arrSize - 1) / 2;
            }

        }

        while (q != 0) {

            if (arr[nArrSize] == arrNum[i]) {
                result[i] = (nArrSize + 1);
                q = 0;
            }

            else if ((newStart == newEnd)) {

                if (arr[nArrSize] == arrNum[i]) {
                    result[i] = (nArrSize + 1);
                    q = 0;
                }

                else {
                    result[i] = -1;
                    q = 0;
                }
            }



            else if (arrNum[i] > arr[nArrSize]) {

                if (((newStart + newEnd) % 2) == 0) {
                    nArrSize = (newStart + newEnd) / 2;
                }
                else {

                    nArrSize = ((newStart + newEnd) / 2) + 1;

                }

                newStart = nArrSize;
            }

            else if (arrNum[i] < arr[nArrSize]) {

                if (((newStart + newEnd) % 2) == 0) {
                    nArrSize = (newStart + newEnd) / 2;
                }
                else {

                    nArrSize = ((newStart + newEnd) / 2);

                }

                newEnd = nArrSize;

            }

        }

    }

    for (int i = 0; i < operationsNum; i++) {
        cout << result[i] << "";
    }

}