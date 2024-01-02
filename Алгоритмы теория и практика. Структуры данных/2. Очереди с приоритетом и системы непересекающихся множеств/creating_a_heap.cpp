#include <iostream>
#include <vector>
#include <deque>


using namespace std;

int sizeH;
int minIndex;
int l;
int r;
int sw;

vector <int> H;
vector <pair <int, int>> answ;


void siftDown(int i) {

    minIndex = i;

    l = 2 * i + 1;

    if ((l < sizeH) and (H[l] < H[minIndex])) {
        minIndex = l;
    }

    r = 2 * i +2;
    if ((r < sizeH) and (H[r] < H[minIndex])) {
        minIndex = r;
    }
     
    if (i != minIndex) {
        answ.push_back(make_pair(i, minIndex));
        sw = H[i];
        H[i] = H[minIndex];
        H[minIndex] = sw;
        siftDown(minIndex);
    }

}

int main() {
    int inp;

    cin >> sizeH;

    for (int i = 0; i < sizeH; ++i) {
        cin >> inp;
        H.push_back(inp);
    }

    for (int i = sizeH/2; i >= 0; --i) { 
        siftDown(i);
    }

    cout << answ.size() << endl;
    for (int i = 0; i < answ.size(); ++i) {
        cout << answ[i].first << " " << answ[i].second << endl;
    }

    return 0;
}