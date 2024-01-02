#include <iostream>
#include <vector>

using namespace std;

vector <int> parent;
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
    sizeT[dst] += sizeT[src];
    sizeT[src] = 0;

    if (sizeT[dst] > maxSize) {
     
        maxSize = sizeT[dst];
    }

}

int main() {

    vector <int> res;

    parent.push_back(0);
    sizeT.push_back(0);

    int numTables = 0;
    int numRequest = 0;

    cin >> numTables;
    cin >> numRequest;

    int temp = 0;

    for (int x = 0; x < numTables; ++x) {

        cin >> temp;

        if (temp > maxSize) {
            maxSize = temp;
        }

        sizeT.push_back(temp);
        parent.push_back(x+1); 
    }

    int dst = 0;
    int src = 0;

    for (int l = 0; l < numRequest; ++l) {

        cin >> dst;
        cin >> src;

        unionT (dst, src);

        res.push_back(maxSize);

    }

    for (int x = 0; x < numRequest; ++x) {

        cout << res[x] << endl;

    }

    return 0;
}