#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    int nim;
    string nama;
    Mahasiswa* next;
};

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(Mahasiswa*& head, int nim, string nama) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(Mahasiswa* head, int nim) {
    Mahasiswa* current = head;
    while (current != nullptr) {
        if (current->nim == nim) {
            cout << "Mahasiswa ditemukan: " << current->nama << endl;
            return;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan NIM(" << nim << ") tidak ditemukan" << endl;
}

// Fungsi untuk mencetak seluruh data mahasiswa
void cetakMahasiswa(Mahasiswa* head) {
    Mahasiswa* current = head;
    while (current != nullptr) {
        cout << "NIM: " << current->nim << ", Nama: " << current->nama << endl;
        current = current->next;
    }
}

int main() {
    Mahasiswa* head = nullptr;
    tambahMahasiswa(head, 12345, "Budi");
    tambahMahasiswa(head, 67890, "Siti");

    cout << "Daftar Mahasiswa:" << endl;
    cetakMahasiswa(head);

    cout << "Cari Mahasiswa dengan NIM 12345:" << endl;
    cariMahasiswa(head, 12345);

    return 0;
}
