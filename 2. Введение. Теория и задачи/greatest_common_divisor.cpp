#include <cassert>
#include <iostream>

using namespace std;

int NOD(int a, int b) {

    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a; 
    }
    else if (a >= b) {
        a = a % b; 
        NOD(a, b);
    }
    else if (b >= a) {
        b = b % a;
        NOD(a, b);
    }

}

int main(void) {
    int a, b;
    std::cin >> a >> b;




    std::cout << NOD(a,b) << std::endl;
    return 0;
}