#include "list.h"
using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmList();
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    address p = first(L);
    while (p != NULL) {
        std::cout << info(p) << " ";
        p = next(p);
    }
    std::cout <<  std::endl;
}

//have fun session
void insertAfter(address prec, address P) {
    next(P) = next(prec);
    next(prec) = P;
}
void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address temp = first(L);
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = P;
    }
    next(P) = NULL;
    //P = first(L);
    //next(P) = P;
}

void deleteAfter(address prec, address P) {
    P = next(prec);
    next(prec) = next(P);
}

void deleteLast(List &L, address P) {
    P = first(L);
    P = next(P);
    next(P) = NULL;
}

address searchList(List L, infotype x) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
