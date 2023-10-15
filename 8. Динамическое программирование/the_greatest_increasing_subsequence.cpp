#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lonDecSub (vector<int> const& a) {

    int n = a.size();

    if (n == 1) { // если длина массива 1 то выводим это число
        cout << "1" << endl;
        cout << "1";
        return 0;
        }

    else if (n == 2) { // если длина массива 2, то выводим числа в зависимости от условий
        if (a[0] > a[1]) {
            cout << "2" << endl;
            cout << "1" << " " << "2";
            return 0;
        }
        else if (a[0] < a[1]) {
            cout << "1" << endl;
            cout << "2";
            return 0;
        }
        else {
            cout << "2" << endl;
            cout << "1" << " " << "2";
            return 0;
        }
    }

    const int INF = 1e9; // числа в массиве не более 10^9 (по условия задачи)
    int l = 0; // первое меньшее значение в "главном" массиве, чем текущее число в массиве а[i] 
    int len = 0; // длина последовательности

    vector<int> m(n + 1, -INF); //"главный" массив, все значения -10^9
    vector<int> mi(n + 1, 0); // массив индексов "главного массива"
    vector<pair<int, int>> anc; // anc.first значение числа l, anc.second итерации первого цикла for 

    m[0] = INF; // первое значение в "главнном" массиве. Тогда получим "главный" массив m (при n = 5) вида: 

    /*
    
    [1000000000, -1000000000, -1000000000, -1000000000, -1000000000, -1000000000] 
    
    */

    vector <int> re(n + 1, -1);

    for (int i = 0; i < n; i++) { // находим последовательность для расчета длины

        l = m.rend() - lower_bound(m.rbegin(), m.rend(), a[i]);

        if ((m[l-1] >= a[i]) && (a[i] > m[l + 1])) {

            if (a[i] == m[l]) {
                int e = l+1;

                while (a[i] == m[e]) {
                    ++e;
                }
                re[i] = mi[e];
                m[e] = a[i];
                mi[e] = i + 1;
                anc.push_back(make_pair(l, i+1));
            }
            else {
                re[i] = mi[l];
                m[l] = a[i];
                mi[l] = i + 1;
                anc.push_back(make_pair(l, i + 1));
            }

        }
    }

    for (int l = 0; l <= n; l++) { // находим длину последовательности 
        if (m[l] < INF && m[l] > -INF)
            ++len;
    }

    cout << len << endl;

        vector<int> res(len);
        int yui = n-1;
        int dfdf = len;

        while (dfdf > 0) { // восстановление последовательности, зная длину и последнее число последовательности 

            if (anc[yui].first == dfdf) {
                res[dfdf-1] = anc[yui].second;
                --dfdf;
            }
            else {
                --yui;
            }

        }

            for (int x = 0; x < len; ++x) {
       cout << res[x] << " ";
    }

            return 0;
}

int main() {

    int numCount;

    cin >> numCount;
    vector <int> nums(numCount);

    for (int a = 0; a < numCount; a++) {
        cin >> nums[a];
    }

    lonDecSub(nums);

    return 0;
}