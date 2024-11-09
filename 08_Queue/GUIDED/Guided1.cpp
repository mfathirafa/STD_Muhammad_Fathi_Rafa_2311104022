#include <iostream>
using namespace std;
/*deklarasi*/
const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if(back == 0){
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if(isFull()) {
        cout << "antiran penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - i; i++) {
            queueTeller[i] = queueTeller[i+1];
        }
        queueTeller[back -1]="",
        back--;
    }
}

int countQueue(){
    return back;
}

void clearQueue(){
    if(isEmpty()) {
        cout << "antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
        cout << i + 1 << ". (kosong)" << endl;
    }
    }
}

int main()
{
    enqueueAntrian("andi");
    enqueueAntrian("maya");
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    return 0;
}