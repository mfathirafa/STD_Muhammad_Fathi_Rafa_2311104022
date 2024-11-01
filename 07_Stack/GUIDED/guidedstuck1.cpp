#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return top == maksimal;
}

bool isEmpty() {
    return top == 0;
}

void pushArrayBuku(string data) {
    if(isFull()) {
        cout << "data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if(isEmpty()) {
        cout << "tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top-1] = "";
        top--;
    }
}

void peekArrayBbuku(int posisi) {
    if(isEmpty()) {
        cout << "tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top - posisi;
        if (index >= 0 && index < top) {
            cout << "posisi ke " << posisi << " adalah " << arrayBuku[index];
        } else {
            cout << "posisi di luar jangkauan" << endl;
        }
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    int index = top - posisi;
    if (index >= 0 && index < top) {
        arrayBuku[index] = data;
    } else {
        cout<< "posisi melebihi data data yang ada" << endl;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if(isEmpty()) {
        cout << "tidak ada data yang dicetak" << endl; 
    } else {
        for (int i = top -1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Strutktur data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n" << endl;

    cout << "apakah data stuck penuh?" << (isFull()? "Ya": "Tidak") << endl;
    cout << "apakah data stuck kosong?" << (isEmpty()? "Ya" : "Tidak") << endl;

    peekArrayBbuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "top setelah destroy: " << top << endl;
    cetakArrayBuku();
    
    return 0;
}