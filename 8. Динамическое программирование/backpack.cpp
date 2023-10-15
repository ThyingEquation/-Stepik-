#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void knapsackW(vector<int> const& A, int W, int n) {


    int i;
    int j;

    //                     \/ rows        \/ columns
    vector<vector<int> > D(W + 1, vector<int>(n + 1));


    for (int a = 0; a < n + 1; a++) {
        D[0][a] = 0;
    }

    for (int a = 0; a < W+1; a++) {
        D[a][0] = 0;
    }

    for (i = 1; i < n+1; i++) {

        for (j = 1; j < W+1; j++) {


            if (A[i-1] > j) {

                D[j][i] = D[j][i - 1];
            }

            else {

                D[j][i] = max({  (D[j][i - 1]),    (D[j - A[i - 1]][i - 1] + A[i - 1])    });
            }

        }
    }

    cout << D[W][n];

}


int main() {

    vector <char> A; // n and i == vertical  - rows ==
    vector <char> B; // m and j == horizontal  - columns ==

    char x;

    int countN; // == vertical - rows ==
    int W;      // == horizontal  - columns ==


    cin >> W;
    cin >> countN;

    vector <int> num(countN);

    for (int i = 0; i < countN; i++) {
        cin >> num[i];
    }

    knapsackW(num, W, countN);


    return 0;
}