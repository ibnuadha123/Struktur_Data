#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = NULL;

void push(char data) {
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop() {
    char data = top->data;

    Node* temp = top;
    top = top->next;

    delete temp;

    return data;
}

int main() {
    string kata;

    cout << "masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    cout << "kata setelah dibalik: ";

    while (top != NULL) {
        cout << pop();
    }

    cout << endl;

    return 0;
}
