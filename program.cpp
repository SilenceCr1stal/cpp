#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

bool isPalindrome(int num, int& pI);

int level(int num) {
    if (num == 1) {
        return 10;
    } else {
        return 10 * level(num - 1);
    }
}

int main(int argc, char **argv) {
    
    int n;

    int i = 0;

    int* pI = &i;

    std::cin >> n;

    int symbols = n;

    for (;;) {
        if (symbols > 10) {
            symbols /= 10;
            ++i;
        } else {
            *pI = *pI + 1;
            break;
        }
    }

    if (isPalindrome(n, *pI)) {
        std::cout << n << " is a palindrome" << std::endl;
    } else {
        std::cout << n << " is NOT a palindrome" << std::endl;
    }

    return 0;
}

bool isPalindrome(int num, int& pI) {
    pI /= 2;
    int n = num;
    int n2 = num;
    for (int i = pI; i >= 1; i--) {
        for (;;) {
            if (n > level(i)) {
                n /= 10;
                if (n < level(i)) {
                    n %= 10;
                    n2 %= level(i);
                    if (i != 1) {
                        n2 /= level(i-1);
                    }
                    if (n != n2) {
                        return false;
                    }
                }
            } else {
                n = num;
                n2 = num;
                break;
            }
        }
    }
    return true;
}

// 12321

// 1234321