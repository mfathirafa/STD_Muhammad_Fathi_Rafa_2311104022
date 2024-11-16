#include <iostream>
using namespace std;

//program binary tree

//deklarasi pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

//inisialisasi
void init() {
    root = NULL;
}

//cek node
bool isEmpty(){
    return root == NULL;
}

//buat node baru
void buatNode(char data){
    if(isEmpty()) {
        root = new Pohon{data, NULL, NULL};
        cout << "\nNode" << data << "berhasil dibuat menjadi root." << endl;
    }else{
        cout << "\nPohon sudah dibuat." << endl;
    }
}

//tambah kiri
Pohon *InsertLeft(char data, Pohon *node) {
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } if (node->left != NULL) {
        cout << "\nNode " << node -> data << " sudah ada child kiri" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node-> left = baru;
    cout << "\nNode" << data << "berhasil ditambahkan ke child kiri" << node->data << endl;
    return baru;
}

//tambah kanan
Pohon *InsertRight(char data, Pohon *node){
    if (isEmpty()) {
        cout << "\nbuat tree terlebih dahulu" << endl;
        return NULL;
    } if (node->right != NULL) {
        cout << "\nNode" << node->data << "sudah ada child kanan" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node -> right =  baru;
    cout <<"\nNode " << data << "berhasil ditambahkan ke child kanan" << node -> data << endl;
    return baru;
}

//ubah data tree
void Update(char data, Pohon *node) {
    if(isEmpty()) {
        cout<< "\nBuat tree terlebih dahulu" << endl;
        return;
    } if (!node) {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node -> data;
    node->data = data;
    cout<< "\nNode " << temp << "berhasil diubah menjadi" << data << endl;
}

//lihat isi data tree
void retrieve(Pohon *node){
    if(isEmpty()) {
        cout<< "\nBUat tree terlebih dahulu!" << endl;
        return;
    } if (!node){
        cout<< "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

//cari data
void find(Pohon *node){
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    } if (node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data: '(tidak punya parent)') << endl;
    if (node-> parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node -> parent->left)
            cout << "Sibling: " << node -> parent-> left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

//fungsi main 
int main() {
    init();
    buatNode('A');
    Pohon *nodeB = InsertLeft('B', root);
    Pohon *nodeC = InsertRight('C', root);
    InsertLeft('D', nodeB);
    InsertRight('E', nodeB);
    InsertLeft('F', nodeC);
    InsertRight('G', nodeC);

    cout << "\n== pemanggilan Retrieve";
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout << "\n== pemanggilan find (node B)";
    find(nodeB);

    cout << "\n== pemanggilan find (node C)";
    find(nodeC);

    cout << "\n== pemanggilan update (mengubah node B menjadi Z";
    Update('Z', nodeB);

    cout << "\n== pemanggilan retrieve setelah update";
    retrieve(nodeB);

    return 0;
}