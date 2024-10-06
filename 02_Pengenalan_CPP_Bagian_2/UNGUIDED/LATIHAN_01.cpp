#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah angka: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka: ";
        cin >> arr[i];
    }

    cout << "\nData Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNomor Genap: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }

    cout << "\nNomor Ganjil: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }

    return 0;
}
