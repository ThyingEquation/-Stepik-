#include <iostream>
#include<vector>


using namespace std;

class Fibonacci {
public:
    static int get_remainder(long long n, int m) {


        int i = 0;

        int a = 0, b = 1, c;

        vector <int> num = { 0, 1 };

        for (i; i < m * m; i++)
        {

            c = (a + b) % m;
            a = b;
            b = c;

            num.push_back(c);

            if (a == 0 && b == 1) {

                i = i + 1;

                n = num.at(n % i);

                return n;
            }
        }
    }
};

int main(void) {

  long long n;
  int m;

  std::cin >> n >> m;

  std::cout << Fibonacci::get_remainder(n, m) << std::endl;

  return 0;
}