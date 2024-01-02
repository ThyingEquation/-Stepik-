#include <iostream>
#include <vector>
#include <forward_list>
#include <cmath>
#include <algorithm>

using namespace std;

int pows[] = {1, 263, 69169, 18191447, 784350533, 284188737, 741637313, 50611954, 310943811, 778221726, 672312510, 818188898, 183678669, 307489611, 869767133, 748754383};

long long hashFun(string word, long long m) {

    long long index = 0;
    long long p = 1000000007;
    long long symbol = 0;

    for (int i = 0; i < word.length(); ++i) {

        symbol = word[i];
        index = index + symbol*pows[i];
    }

    index = (index % p) % m;

    return index;
}



int main() {

    int tableS = 0;
    int commandsCount = 0;
    int indexI = 0;
    int findflag = 0;
    int index = 0;
    string command = "";
    string word = "";

    cin >> tableS; 
    cin >> commandsCount; 

    vector <forward_list <string>> CH (tableS);


    for (int i = 0; i < commandsCount; ++i) {

        cin >> command;

        if (command == "add") {
            cin >> word;
            index = hashFun(word, tableS);

            auto current = CH[index].begin(); 
            auto end = CH[index].end();      
            while (current != end)
            {
                if (*current == word) {
                    findflag = 1;
                }
                current++;
            }

            if (findflag == 0) {
                CH[index].push_front(word);
            }

            else if (findflag == 1) {
                findflag = 0;
            }
          
        }

        else if (command == "del") { 
            cin >> word;
            index = hashFun(word, tableS);

            
            auto current = CH[index].begin();
            auto current0 = current;
            auto end = CH[index].end();

            while (current != end)
            {
                if (*current == word) {

                    if (current == current0) {
                        findflag = 2;
                    }

                    else {
                        findflag = 1;
                    }
                }

                if (findflag == 0) {

                    current0 = current;
                }

                current++;
                
            }

            if (findflag == 1) {

                    findflag = 0;
                    CH[index].erase_after(current0);
                
            }

            else if (findflag == 2) {

                findflag = 0;
                CH[index].pop_front();

            }

        }

        else if (command == "find") {
            cin >> word;
            index = hashFun(word, tableS);

            auto current = CH[index].begin(); 
            auto end = CH[index].end();       
            while (current != end)
            {
                if (*current == word) {
                    findflag = 1;
                }
                current++;
            }

            if (findflag == 1) {
                findflag = 0;
                cout << "yes" << endl;
            }

            else {
                cout << "no" << endl;
            }
        
        }

        else if (command == "check") {
            cin >> indexI;
            auto current = CH[indexI].begin(); 
            auto end = CH[indexI].end();       
            while (current != end)
            {
                std::cout << *current << " "; 
                current++;
            }
            std::cout << endl;
        }

    }

    return 0;
}
