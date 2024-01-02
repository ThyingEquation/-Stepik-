#include <iostream>
#include <vector>

using namespace std;

void inOrder(vector <vector <int> > & tree, int i) {

    if (tree[i][1] != -1) inOrder(tree, tree[i][1]);
    cout << tree[i][0] << ' '; //убрать, если не нужен вывод в консоль
    if (tree[i][2] != -1) inOrder(tree, tree[i][2]);

}

void preOrder(vector <vector <int> > & tree, int i) {

    cout << tree[i][0] << ' '; //убрать, если не нужен вывод в консоль
    if (tree[i][1] != -1) preOrder(tree, tree[i][1]);
    if (tree[i][2] != -1) preOrder(tree, tree[i][2]);

}

void postOrder(vector <vector <int> > & tree, int i) {

    if (tree[i][1] != -1) postOrder(tree, tree[i][1]);
    if (tree[i][2] != -1) postOrder(tree, tree[i][2]);
    cout << tree[i][0] << ' '; //убрать, если не нужен вывод в консоль
    
}

int main() {

    int value;

    cin >> value;

    int widht = 3;
 
    vector <vector <int>> tree (value, vector <int>(widht)); // value строк, widht стобцов

    for (int i = 0; i < value; i++) {   // Цикл, который идёт по строкам
        for (int j = 0; j < widht; j++)
        {
            cin >> tree[i][j];
        }
    }


    inOrder (tree, 0);

    cout << endl;

    preOrder(tree, 0);

    cout << endl;

    postOrder(tree, 0);

    cout << endl;

    return 0;
}
