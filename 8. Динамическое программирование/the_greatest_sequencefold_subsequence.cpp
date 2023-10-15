#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
           // if (a[i] > a[j]) {
            if (a[i] % a[j] == 0) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

  //  for (int r = 0; r < d.size(); r++) {
  //      cout << d[r];
  //  }
    cout << endl;

    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}


int main()
{
    int numOfArr;
    cin >> numOfArr;

    vector <int> arr(numOfArr);

    for (int a = 0; a < numOfArr; a++) {

        cin >> arr[a];
    }

    cout << lis(arr);

    return 0;
}
