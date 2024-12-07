#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string tanggal_pengembalian;
};

typedef Buku infotypeBuku;
typedef struct ElmBuku *addressBuku;

struct ElmBuku {
    infotypeBuku info;
    addressBuku next;
};

struct Anggota {
    string nama;
    string id_anggota;
    ElmBuku* buku_head; // Pointer ke buku yang dipinjam
    Anggota* next;
};

typedef Anggota infotypeAnggota;
typedef struct ElmAnggota *addressAnggota;

struct ElmAnggota {
    infotypeAnggota info;
    addressAnggota next;
};

struct ListAnggota {
    addressAnggota first;
};

// Membuat list anggota kosong
void createListAnggota(ListAnggota &L) {
    L.first = nullptr;
}

// Membuat elemen anggota baru
addressAnggota allocateAnggota(infotypeAnggota data) {
    addressAnggota P = new ElmAnggota;
    P->info = data;
    P->info.buku_head = nullptr; // Inisialisasi buku_head
    P->next = nullptr;
    return P;
}

// Menambahkan anggota di awal
void insertFirstAnggota(ListAnggota &L, addressAnggota P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

// Menambahkan buku ke anggota tertentu
void insertBuku(addressAnggota anggota, infotypeBuku data) {
    addressBuku P = new ElmBuku;
    P->info = data;
    P->next = anggota->info.buku_head;
    anggota->info.buku_head = P;
}

// Menampilkan data anggota dan buku
void printListAnggota(const ListAnggota &L) {
    addressAnggota P = L.first;
    while (P != nullptr) {
        cout << "Anggota: " << P->info.nama << ", ID: " << P->info.id_anggota << endl;
        addressBuku buku = P->info.buku_head;
        while (buku != nullptr) {
            cout << "  Buku: " << buku->info.judul << ", Tanggal Pengembalian: " << buku->info.tanggal_pengembalian << endl;
            buku = buku->next;
        }
        cout << endl;
        P = P->next;
    }
}

int main() {
    ListAnggota L;
    createListAnggota(L);

    // Membuat data anggota
    infotypeAnggota a1 = {"Rani", "A001"};
    infotypeAnggota a2 = {"Dito", "A002"};
    infotypeAnggota a3 = {"Vina", "A003"};

    // Alokasi elemen anggota
    addressAnggota anggota1 = allocateAnggota(a1);
    addressAnggota anggota2 = allocateAnggota(a2);
    addressAnggota anggota3 = allocateAnggota(a3);

    // Memasukkan anggota ke list
    insertFirstAnggota(L, anggota1);
    insertFirstAnggota(L, anggota2);
    insertFirstAnggota(L, anggota3);

    // Menambahkan buku
    insertBuku(anggota1, {"Pemrograman C++", "01/12/2024"});
    insertBuku(anggota2, {"Algoritma Pemrograman", "15/12/2024"});
    insertBuku(anggota1, {"Struktur Data", "10/12/2024"}); // Buku baru untuk Rani

    // Cetak isi list anggota dan buku
    cout << "Data Anggota Perpustakaan dan Buku yang Dipinjam:" << endl;
    printListAnggota(L);

    return 0;
}