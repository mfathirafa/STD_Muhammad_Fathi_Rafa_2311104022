/*1. Mencari elemen tertentu di SLL*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke akhir linked list
void insertEnd_2311104022(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk mencari elemen dalam linked list
void searchElement_2311104022(Node* head, int value) {
    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Elemen ditemukan di posisi: " << position 
                 << " dengan alamat: " << current << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Elemen " << value << " tidak ditemukan dalam list." << endl;
    }
}

int main() {
    Node* head = nullptr;

    // Memasukkan 6 elemen ke dalam linked list
    for (int i = 0; i < 6; ++i) {
        int value;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> value;
        insertEnd_2311104022(head, value);
    }

    // Mencari elemen dalam linked list
    int cari;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;
    searchElement_2311104022(head, cari);

    return 0;
}