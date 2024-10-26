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
void bubbleSortList_2311104022(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void printList_2311104022(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Memasukkan 5 elemen ke dalam linked list
    for (int i = 0; i < 5; ++i) {
        int value;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> value;
        insertEnd_2311104022(head, value);
    }

    cout << "List sebelum diurutkan: ";
    printList_2311104022(head);

    // Mengurutkan linked list
    bubbleSortList_2311104022(head);

    cout << "List setelah diurutkan: ";
    printList_2311104022(head);

    return 0;
}
