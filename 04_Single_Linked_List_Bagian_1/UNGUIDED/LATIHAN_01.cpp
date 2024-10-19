#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertDepan(int nilai) {
        Node* nodeBaru = new Node();
        nodeBaru->data = nilai;
        nodeBaru->next = head;
        head = nodeBaru;
    }

    void insertBelakang(int nilai) {
        Node* nodeBaru = new Node();
        nodeBaru->data = nilai;
        nodeBaru->next = nullptr;

        if (head == nullptr) {
            head = nodeBaru;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nodeBaru;
        }
    }

    void cetak() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertDepan(10);
    list.insertBelakang(20);
    list.insertDepan(5);

    cout << "Isi Linked List: ";
    list.cetak();

    return 0;
}
