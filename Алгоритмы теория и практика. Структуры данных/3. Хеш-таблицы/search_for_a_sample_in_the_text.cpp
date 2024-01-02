#include <iostream>
#include <vector>


using namespace std;


int main() {

    string pattern, text;

    cin >> pattern;
    cin >> text;

    if (pattern.length() == text.length()) {

        if (pattern == text) {

            cout << 0;
            return 0;

        }

        else { return 0; }

    }

    string s = pattern + "$" + text;

    int n = (int)s.length();
    int b = (int)pattern.length();
    int h = b + 1;

    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }

        if (z[i] == b) {

            cout << i - h << " ";

        }
    }

    return 0;
}
