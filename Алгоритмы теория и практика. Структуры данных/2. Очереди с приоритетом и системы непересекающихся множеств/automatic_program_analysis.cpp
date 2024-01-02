#include <iostream>
#include <vector>

using namespace std;

vector <int> parent;
vector <pair<int,int>> Enums;
vector <pair<int,int>> Dnums;


vector <int> sizeT;

int maxSize = 0;

int findT (int v) {
    if (v == parent[v]) {
        return v;
     }

    return parent[v] = findT (parent[v]);
}

void unionT (int dst, int src) { 

    dst = findT (dst);
    src = findT (src);

    if (dst == src) {

        return;
    }

    parent[src] = dst;
   
}

int main() {

    parent.push_back(0);

    int numCount;
    int EnumCount;
    int DnumCount;

    cin >> numCount;
    cin >> EnumCount;
    cin >> DnumCount;

    int temp1 = 0;
    int temp2 = 0;

    for (int x = 0; x < numCount; ++x) {
        parent.push_back(x+1); 
    }

    for (int x = 0; x < EnumCount; ++x) {

        cin >> temp1;
        cin >> temp2;

        unionT(temp1, temp2);
    }

    for (int x = 0; x < DnumCount; ++x) {

        cin >> temp1;
        cin >> temp2;

        if (findT(temp1) == findT(temp2)) {

            cout << 0;
            return 0;

        }

    }

    cout << 1;

    int dst = 0;
    int src = 0;


    return 0;
}