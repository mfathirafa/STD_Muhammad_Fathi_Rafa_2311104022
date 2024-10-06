#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &arr, int baris, int kolom, int kedalaman) {
    int indeks = 0;
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            for(int k = 0; k < kedalaman; k++) {
                cout << arr[indeks] << " ";
                indeks++;
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int baris, kolom, kedalaman;

    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;
    cout << "Masukkan jumlah kedalaman: ";
    cin >> kedalaman;

    vector<int> arrayTigaDimensi(baris * kolom * kedalaman);

    arrayTigaDimensi = {2, 5, 8, 10, 22, 44, 33};

    printArray(arrayTigaDimensi, baris, kolom, kedalaman);

    return 0;
}
