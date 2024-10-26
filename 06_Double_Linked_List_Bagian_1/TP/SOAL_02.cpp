#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menambahkan elemen di akhir list
void insertLast_2311104022(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menghapus elemen pertama dalam list
void deleteFirst_2311104022(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Fungsi untuk menghapus elemen terakhir dalam list
void deleteLast_2311104022(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;

    if (head->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

// Fungsi untuk mencetak elemen dari depan ke belakang
void printList_2311104022(Node* head) {
    Node* temp = head;
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Menambah elemen ke dalam list
    insertLast_2311104022(head, 10);
    insertLast_2311104022(head, 15);
    insertLast_2311104022(head, 20);

    cout << "DAFTAR ANGGOTA LIST SEBELUM PENGHAPUSAN: ";
    printList_2311104022(head);

    // Menghapus elemen pertama dan terakhir
    deleteFirst_2311104022(head);
    deleteLast_2311104022(head);

    // Menampilkan hasil list setelah penghapusan
    printList_2311104022(head);

    return 0;
}
