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
void printList_2311104022(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void insertSorted_2311104022(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Memasukkan 4 elemen terurut secara manual
    for (int i = 0; i < 4; ++i) {
        int value;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> value;
        insertSorted_2311104022(head, value);
    }

    // Menambah elemen baru secara terurut
    int newValue;
    cout << "Masukkan elemen baru yang ingin ditambahkan: ";
    cin >> newValue;
    insertSorted_2311104022(head, newValue);

    cout << "List setelah elemen baru dimasukkan: ";
    printList_2311104022(head);

    return 0;
}
