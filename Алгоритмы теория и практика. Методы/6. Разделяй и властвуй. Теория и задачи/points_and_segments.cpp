#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sNum = 0;
int eNum = 0;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        do {

            i++;

        } while (arr[i] < pivot);


        do {

            j--;

        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

int partition_r(vector<int>&  arr, int low, int high) {

    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[low]);

    return partition(arr, low, high);
}




void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high) {

        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}



int get_pos(const vector<int>& numbers, int number, int type) {

    int l = 0;
    int r = numbers.size() - 1;
    int m = (l + r) / 2;

    while (l <= r) {

        m = (l + r) / 2;

        if (numbers[m] == number) {

            if (type == 1) {
                sNum = m + 1;
                l = m + 1;
            }

            else if (type == 2) {
                eNum = m;
                r = m - 1;
            }
        }

        else if (numbers[m] > number) {

            if (type == 2) {
                eNum = m;
            }

            r = m - 1;
        }

        else {

            l = m + 1;

            if (type == 1) {
                sNum = m + 1;
                l = m + 1;
            }

            else {
                eNum = m + 1;
            }
        }
    }
    return -1;
}



int main()
{

    int res = 0;


    int numOfLines;
    cin >> numOfLines;

    int numOfPoints;
    cin >> numOfPoints;

    vector <int> starts;
    vector <int> ends;
    vector <int> points;

    for (int a = 0; a < numOfLines; a++) {

        int temp1;
        int temp2;
        cin >> temp1;
        cin >> temp2;
        starts.push_back(temp1);
        ends.push_back(temp2);
    }

    for (int a = 0; a < numOfPoints; a++) {
        int temp1;
        cin >> temp1;
        points.push_back(temp1);
    }

    quickSort(starts, 0, numOfLines - 1);
    quickSort(ends, 0, numOfLines - 1);

    for (int i = 0; i < numOfPoints; i++) {

              get_pos(starts, points[i], 1);
              get_pos(ends, points[i], 2);

              cout << sNum - eNum << " ";

              sNum = 0;
              eNum = 0;

    }


    return 0;
}