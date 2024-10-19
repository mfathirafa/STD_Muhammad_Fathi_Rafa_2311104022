#include "list.h"

int main() {
    // List L;
    // createList(L);

    // int input;

    // std::cout << "Digit 1: ";
    // std::cin >> input;
    // address P = allocate(input);
    // insertFirst(L, P);
    // printInfo(L);

    // std::cout << "Digit 2: ";
    // std::cin >> input;
    // P = allocate(input);
    // insertFirst(L, P);
    // printInfo(L);

    // std::cout << "Digit 3: ";
    // std::cin >> input;
    // P = allocate(input);
    // insertFirst(L, P);
    // printInfo(L);

    // return 0;

    // have fun session

    List L;
    createList(L);

    int input;
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << " : ";
        cin >> input;

        address P = allocate(input);
        insertLast(L, P);

    }

    cout << "Isi list : ";
    printInfo(L);

    return 0;
}
