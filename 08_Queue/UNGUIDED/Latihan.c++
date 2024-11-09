#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk node pada linked list
struct Mahasiswa {
    string nama;
    int NIM;
    Mahasiswa* next;
};

// Queue untuk mengelola antrean mahasiswa berdasarkan prioritas NIM
class Queue {
private:
    Mahasiswa* front; // pointer ke elemen pertama
    Mahasiswa* rear;  // pointer ke elemen terakhir

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan mahasiswa ke dalam antrean
    void enqueue(string nama, int NIM) {
        Mahasiswa* newMahasiswa = new Mahasiswa();
        newMahasiswa->nama = nama;
        newMahasiswa->NIM = NIM;
        newMahasiswa->next = nullptr;

        // Menempatkan berdasarkan prioritas NIM (semakin kecil NIM, semakin tinggi prioritas)
        if (isEmpty() || NIM < front->NIM) {
            newMahasiswa->next = front;
            front = newMahasiswa;
            if (rear == nullptr) rear = front; // Jika queue kosong, rear juga menunjuk ke front
        } else {
            Mahasiswa* current = front;
            while (current->next != nullptr && current->next->NIM <= NIM) {
                current = current->next;
            }
            newMahasiswa->next = current->next;
            current->next = newMahasiswa;
            if (newMahasiswa->next == nullptr) rear = newMahasiswa;
        }
    }

    // Menghapus mahasiswa dari antrean
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong." << endl;
            return;
        }
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
    }

    // Menampilkan antrean mahasiswa
    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrean kosong." << endl;
        } else {
            Mahasiswa* current = front;
            cout << "Antrean Mahasiswa (prioritas berdasarkan NIM):" << endl;
            while (current != nullptr) {
                cout << "Nama: " << current->nama << ", NIM: " << current->NIM << endl;
                current = current->next;
            }
        }
    }

    // Menghapus semua antrean
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Antrean telah dikosongkan." << endl;
    }
};

int main() {
    Queue queue;
    int pilihan;
    string nama;
    int NIM;

    do {
        cout << "\nMenu Queue:\n";
        cout << "1. Tambah Mahasiswa ke Antrean\n";
        cout << "2. Hapus Mahasiswa dari Antrean\n";
        cout << "3. Tampilkan Antrean Mahasiswa\n";
        cout << "4. Kosongkan Antrean\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> NIM;
                queue.enqueue(nama, NIM);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                queue.clearQueue();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
