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

// Fungsi untuk menampilkan elemen dari depan ke belakang
void printForward_2311104022(Node* head) {
    cout << "Daftar elemen dari depan ke belakang: ";
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan elemen dari belakang ke depan
void printBackward_2311104022(Node* tail) {
    cout << "Daftar elemen dari belakang ke depan: ";
    while (tail != nullptr) {
        cout << tail->data;
        if (tail->prev != nullptr) cout << " <-> ";
        tail = tail->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Memasukkan 4 elemen ke dalam list
    for (int i = 1; i <= 4; ++i) {
        int value;
        cout << "Masukkan elemen ke-" << i << ": ";
        cin >> value;
        insertLast_2311104022(head, value);
    }

    // Menampilkan elemen dari depan ke belakang
    printForward_2311104022(head);

    // Menentukan node terakhir untuk menampilkan elemen dari belakang ke depan
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    printBackward_2311104022(tail);

    return 0;
}
