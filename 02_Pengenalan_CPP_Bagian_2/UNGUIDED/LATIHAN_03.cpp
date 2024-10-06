#include <iostream>
using namespace std;

int main() {
    int jumlahElemen;

    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> jumlahElemen;

    int* array = new int[jumlahElemen];
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < jumlahElemen; i++) {
        cout << "Elemen " << (i + 1) << ": ";
        cin >> array[i];
    }

    int maks = array[0], min = array[0];
    double total = 0;

    for (int i = 0; i < jumlahElemen; i++) {
        if (array[i] > maks) maks = array[i];
        if (array[i] < min) min = array[i];
        total += array[i];
    }

    cout << "Nilai maksimum: " << maks << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << (total / jumlahElemen) << endl;

    return 0;
}
