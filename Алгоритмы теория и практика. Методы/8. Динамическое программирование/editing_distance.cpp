#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void editDist (vector<char> const& A, vector<char> const& B) {
   
    int aS = A.size() + 1;
    int bS = B.size() + 1;
    int c = 0;
    int i;
    int j;

    //                      \/ rows         \/ columns
    vector<vector<int> > D (aS, vector<int>(bS));

    for (int a = 0; a < bS; a++) {
        D[0][a] = a;
    }

    for (int a = 0; a < aS; a++) {
        D[a][0] = a;
    }


    for (i = 1; i < aS; i++) {

        for (j = 1; j < bS; j++) {

            c = (A[i - 1] == B[j - 1]) ? 0 : 1;

            D[i][j] = min({(D[i - 1][j] + 1), (D[i][j - 1] + 1), (D[i - 1][j - 1] + c)});
         }
    }

    cout << D[i-1][j-1];
}

int main() {

    vector <char> A; // n and i == vertical  - rows ==
    vector <char> B; // m and j == horizontal  - columns ==

    char x;

    while (cin.get(x)) {
        if (x == '\n') break;
        A.push_back(x);
    }

    while (cin.get(x)) {
        if (x == '\n') break;
        B.push_back(x);
    }

    editDist(A,B);

    return 0;
}