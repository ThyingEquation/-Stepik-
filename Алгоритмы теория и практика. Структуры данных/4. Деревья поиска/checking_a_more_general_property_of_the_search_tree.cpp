#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int maxV = -pow(2, 31);

int fff = 0;

int root = 0;

void inOrder(vector <vector <int> >& tree, int i) {

 
    if (tree[i][1] != -1) {
        if (tree[i][0] > tree[tree[i][1]][0]) {
            inOrder(tree, tree[i][1]);
        }
        else {
            fff = 1;
            return;
        }
    }

          if (maxV > tree[i][0]) {
          fff = 1;
          return;
      }
      else { maxV = tree[i][0]; }


    if (tree[i][2] != -1) {

        if (tree[i][0] <= tree[tree[i][2]][0]) {
            inOrder(tree, tree[i][2]);
        }
        else {
            fff = 1;
            return;
        }
    }
    
}


int main() {

    int value;

    cin >> value;

    if (value == 0) {

        cout << "CORRECT";
        return 0;

    }

    int widht = 3;
 
    vector <vector <int>> tree (value, vector <int>(widht)); // value строк, widht стобцов

    for (int i = 0; i < value; i++) {  
        for (int j = 0; j < widht; j++)
        {
            cin >> tree[i][j];
        }

    }

    inOrder (tree, 0);

    if (fff == 0) { cout << "CORRECT"; }
    else { cout << "INCORRECT"; }

    return 0;
}
