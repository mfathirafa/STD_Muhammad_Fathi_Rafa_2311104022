#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string nama;
    int durasi;
};

typedef Proyek infotypeProyek;
typedef struct ElmProyek *addressProyek;

struct ElmProyek {
    infotypeProyek info;
    addressProyek next;
};

struct Pegawai {
    string nama;
    string id_pegawai;
    ElmProyek* proyek_head; // Pointer ke proyek
    Pegawai* next;
};

typedef Pegawai infotypePegawai;
typedef struct ElmPegawai *addressPegawai;

struct ElmPegawai {
    infotypePegawai info;
    addressPegawai next;
};

struct ListPegawai {
    addressPegawai first;
};

// Membuat list pegawai kosong
void createListPegawai(ListPegawai &L) {
    L.first = nullptr;
}

// Membuat elemen pegawai baru
addressPegawai allocatePegawai(infotypePegawai data) {
    addressPegawai P = new ElmPegawai;
    P->info = data;
    P->info.proyek_head = nullptr; // Inisialisasi proyek_head
    P->next = nullptr;
    return P;
}

// Menambahkan pegawai di awal
void insertFirstPegawai(ListPegawai &L, addressPegawai P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

// Menambahkan proyek ke pegawai tertentu
void insertProyek(addressPegawai pegawai, infotypeProyek data) {
    addressProyek P = new ElmProyek;
    P->info = data;
    P->next = pegawai->info.proyek_head;
    pegawai->info.proyek_head = P;
}

// Menampilkan data pegawai dan proyek
void printListPegawai(const ListPegawai &L) {
    addressPegawai P = L.first;
    while (P != nullptr) {
        cout << "Pegawai: " << P->info.nama << ", ID: " << P->info.id_pegawai << endl;
        addressProyek proyek = P->info.proyek_head;
        while (proyek != nullptr) {
            cout << "  Proyek: " << proyek->info.nama << ", Durasi: " << proyek->info.durasi << " bulan" << endl;
            proyek = proyek->next;
        }
        cout << endl;
        P = P->next;
    }
}

int main() {
    ListPegawai L;
    createListPegawai(L);

    // Membuat data pegawai
    infotypePegawai p1 = {"Andi", "P001"};
    infotypePegawai p2 = {"Budi", "P002"};
    infotypePegawai p3 = {"Citra", "P003"};

    // Alokasi elemen pegawai
    addressPegawai pegawai1 = allocatePegawai(p1);
    addressPegawai pegawai2 = allocatePegawai(p2);
    addressPegawai pegawai3 = allocatePegawai(p3);

    // Memasukkan pegawai ke list
    insertFirstPegawai(L, pegawai1);
    insertFirstPegawai(L, pegawai2);
    insertFirstPegawai(L, pegawai3);

    // Menambahkan proyek
    insertProyek(pegawai1, {"Aplikasi Mobile", 12});
    insertProyek(pegawai2, {"Sistem Akuntansi", 8});
    insertProyek(pegawai3, {"E-commerce", 10});
    insertProyek(pegawai1, {"Analisis Data", 6}); // Proyek baru untuk Andi

    // Cetak isi list pegawai dan proyek
    cout << "Data Pegawai dan Proyek:" << endl;
    printListPegawai(L);

    return 0;
}