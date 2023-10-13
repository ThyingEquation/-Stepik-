#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
            int d [40] = {0};
        d[0] = 0;
        d[1] = 1;

        for (int x = 2; x <= n; x++) {

            d[x] = d[x - 1] + d[x - 2];
           
        } 
        n = d[n];
    return n;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}