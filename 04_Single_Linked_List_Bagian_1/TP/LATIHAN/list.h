#ifndef LIST_H
#define LIST_H

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef int infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void printInfo(List L);

//have fun session
void insertAfter(address prec, address P);
void insertLast(List &L, address P);
void deleteAfter(address prec, address P);
void deleteLast(List &, address P);
address searchList(List L, infotype x);

#endif
