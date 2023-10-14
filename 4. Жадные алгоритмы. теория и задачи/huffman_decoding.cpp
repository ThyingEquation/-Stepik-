#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

    int countS;
    int lengthR;
    string result;

    cin >> countS >> lengthR;

    vector <pair <string, string>> symbols(countS);

    for (int i = 0; i < countS; i++) {
        cin >> symbols[i].second >> symbols[i].first;
        symbols[i].second.erase(1, 1);
    }

    cin >> result;

      string cc = "";
      string temp = result;
      int f = 0;
      int ff = 0;

         while (lengthR > 0) {

             cc += temp[f];

             for (int a = 0; a < symbols.size(); a++) {

                 if (symbols[a].first == cc) {

                     result.replace(ff, symbols[a].first.length(), symbols[a].second);
                     lengthR -= symbols[a].first.length();
                     cc = "";
                     ff++;
                    
                 }
                 
             }

             ++f;
         }

     cout << result;

}