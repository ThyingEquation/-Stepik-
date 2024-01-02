#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {

    vector <char> arr;

    vector <pair <int, string>> symbols;
    vector <pair <string, string>> symbols1;
    vector <pair <int, string>> symbols2;

    char c;
    string g;
    string x;
    int xx = 0;
    int r = 0;

    while (cin.get(c)) {
        x = c;
        if (c == '\n') { break; }
        else if (symbols.size() == 0) {

            symbols.push_back(make_pair(1, x));
        }

        else {

            for (int a = 0; a < symbols.size(); a++) {
                if (symbols[a].second == x) {
                    symbols[a].first = ++symbols[a].first;
                    r = 1;
                }
            }

            if (r == 0) {
                symbols.push_back(make_pair(1, x));
            }
        }

        ++xx;
        r = 0;
        g += c;

    }

    sort(symbols.begin(), symbols.end());

    for (int a = 0; a < symbols.size(); a++) {

        symbols1.push_back(make_pair("", symbols[a].second));
    }

    while (symbols.size() != 0) {

        if (symbols.size() > 3) {

            symbols2.push_back(make_pair(0, symbols[0].second));
            symbols2.push_back(make_pair(1, symbols[1].second));
          
            symbols[1].first += symbols[0].first;
            symbols[1].second += symbols[0].second;
            
            symbols[0].first = symbols[2].first;
            symbols[0].second = symbols[2].second;

            for (int q = 2; q < symbols.size() - 1; q++) {

                symbols[q].first = symbols[q + 1].first;
                symbols[q].second = symbols[q + 1].second;
            }

            symbols.pop_back();


            for (int q = 2; q < symbols.size(); q++) {
                string temp = "";
                int tempi = 0;

                if (symbols[q-1].first > symbols[q].first) {

                    tempi = symbols[q].first;
                    temp = symbols[q].second;

                    symbols[q].first = symbols[q-1].first;
                    symbols[q].second = symbols[q - 1].second;

                    symbols[q - 1].first = tempi;
                    symbols[q - 1].second = temp;
                }

                else break;

            }

        }

        else   if (symbols.size() == 3) {

                    symbols2.push_back(make_pair(0, symbols[0].second));
                    symbols2.push_back(make_pair(1, symbols[1].second));

                    symbols[0].first += symbols[1].first;
                    symbols[0].second += symbols[1].second;

                    symbols[1].first = symbols[2].first;
                    symbols[1].second = symbols[2].second;

                    symbols.pop_back();
          
            }

        else if (symbols.size() == 2) {
            symbols2.push_back(make_pair(0, symbols[0].second));
            symbols2.push_back(make_pair(1, symbols[1].second));
            symbols.pop_back();
            symbols.pop_back();
        }

        else if (symbols.size() == 1) {
            symbols2.push_back(make_pair(0, symbols[0].second));
            symbols.pop_back();
        }
    }

    string temp1 = "";;
   

    for (int k = 0; k < symbols1.size(); k++) {

        temp1 = "";

        for (int d = symbols2.size()-1; d >= 0; d--) {

            if (symbols2[d].second.find(symbols1[k].second) != string::npos) {

                temp1 += std::to_string(symbols2[d].first);
                symbols1[k].first = temp1;
            }


        }

    }

    for (int a = 0; a < symbols1.size(); a++) {

        size_t pos;
        while ((pos = g.find(symbols1[a].second)) != string::npos) {
            g.replace(pos, 1, symbols1[a].first);
        }

    }

    cout << symbols1.size() << " " << g.length() << endl;

      for (int a = symbols1.size()-1; a >= 0; a--) {

        cout << symbols1[a].second << ":" << " " << symbols1[a].first << endl;
    }

    cout << g << endl;;

}