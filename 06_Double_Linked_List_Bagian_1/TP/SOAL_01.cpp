#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menambahkan elemen di awal list
void insertFirst_2311104022(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

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

// Fungsi untuk mencetak elemen dari depan ke belakang
void printList_2311104022(Node* head) {
    Node* temp = head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertFirst_2311104022(head, 10);
    insertFirst_2311104022(head, 5);
    insertLast_2311104022(head, 20);

    printList_2311104022(head);

    return 0;
}
