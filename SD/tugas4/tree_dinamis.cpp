#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int data) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->kiri = NULL;
        newNode->kanan = NULL;

        root = newNode;
        return;
    }

    // inputan lebih kecil dari root, masuk ke kiri
    if (data < root->data) {
        tambah(root->kiri, data);
    }

    // inputan lebih besar dari root, masuk ke kanan
    if (data > root->data) {
        tambah(root->kanan, data);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->kiri);
        cout << root->data << " ";
        inorder(root->kanan);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->kiri);
        postorder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0=stop) : ";
    cin >> angka;

    while (angka != 0) {
        tambah(root, angka);
        cin >> angka;
    }

    cout << endl;

    cout << "Pre-order  : ";
    preorder(root);

    cout << endl;

    cout << "In-order   : ";
    inorder(root);

    cout << endl;

    cout << "Post-order : ";
    postorder(root);

    cout << endl;

    return 0;
}
