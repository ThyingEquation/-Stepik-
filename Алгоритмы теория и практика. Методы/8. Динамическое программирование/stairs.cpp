#include <iostream> 
#include <vector>
 using namespace std; 

int main() { 
int countN; 
int b; cin >> countN;
 vector <int> num(countN+1); 
 num[0] = 0;
  cin >> num[1];
   if (countN == 1) { cout << num[1]; return 0; }
    for (int i = 2; i <= countN; i++) {
      cin >> b; 
      num[i] = max(num[i - 1], num[i - 2]) + b; 
      } 
      cout << num[countN]; 
      return 0; } // возможно улучшить без массива?