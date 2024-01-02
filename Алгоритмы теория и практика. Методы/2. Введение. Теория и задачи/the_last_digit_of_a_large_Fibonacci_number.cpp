#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
        int d [2] = {0};
        int y = 0;
        d[0] = 0;
        d[1] = 1;

        for (int x = (n - 2); x >= 0; x--) {

        //    d[x] = d[x - 1] + d[x - 2];
            y = ((d[1] + d[0]) % 10);
            d[0] = d[1];
            d[1] = y;
        } 
        n = y;
    return n;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}