#include <iostream>
#include <vector>

using namespace std;

long minIndex;
long inp;
long l;
long r;
long sw1;
long sw2;

long numCPUs;

vector <pair <long, long>> CPUs;

void siftDown(long i) {

    minIndex = i;

    l = 2 * i + 1;

    if ((l < numCPUs) and (CPUs[l] < CPUs[minIndex])) {
        minIndex = l;
    }

    r = 2 * i + 2;
    if ((r < numCPUs) and (CPUs[r] < CPUs[minIndex])) {
        minIndex = r;
    }

    if (i != minIndex) {
        sw1 = CPUs[i].first;
        sw2 = CPUs[i].second;

        CPUs[i] = CPUs[minIndex];
         
        CPUs[minIndex].first = sw1;
        CPUs[minIndex].second = sw2;
        siftDown(minIndex);
    }
}

int main() {
       
    long numTasks;
    long i = 0;
     
    cin >> numCPUs >> numTasks;


    for (long z = 0; z < numCPUs; ++z) {

        CPUs.push_back(make_pair(0, z));

    }


    for (long v = 0; v < numTasks; ++v) {

        cin >> inp;
        cout << CPUs[0].second << " " << CPUs[0].first << endl;
        CPUs[0].first += inp;

        if (inp > 0) {

            for (long i = 0; i >= 0; --i) {
                siftDown(i);
            }
        }
    }

    return 0;
}