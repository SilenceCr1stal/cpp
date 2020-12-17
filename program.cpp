#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void change(int *a, int *b);
int main(int argc, char **argv) {
    
    int myMark = 5;

    int otherMark = 3;

    const unsigned short int size = 6;

    int arr[size] = {17, 16, 15, 14, 13, 12};

    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << endl;
        switch (i) {
            case size - 1:
                cout << "======================" << endl;
                break;
        }
    }

    int *pArr = arr;

    *(pArr + 3) = 11;

    // cout << arr[3] << endl; // 11

    int mark = 4;

    int *pmark = &mark;

    // cout << pmark << " " << *pmark << endl; // 0x7ffdafb01ddc 4

    *pmark = 5;

    // cout << mark << endl; // 5

    int **ppmark = &pmark;

    // cout << ppmark << " " << **ppmark << endl; // 0x7ffdafb01dd0 5

    **ppmark = 2;

    // cout << mark << endl << "----------------------" << endl; // 2
    
    // cout << myMark << " " << otherMark << endl;

    change(&myMark, &otherMark);

    cout << myMark << endl;

    cout << otherMark << endl;


    int &a = otherMark;

    a++;

    cout << otherMark << endl;

    return 0;
}

void change(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}