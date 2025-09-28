#include <iostream>
using namespace std;

// Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Kelas Stack
class Stack {
private:
    Node* top; // pointer ke elemen teratas
public:
    Stack() {
        top = nullptr;
    }

    // Cek apakah stack kosong
    bool isEmpty() {
        return top == nullptr;
    }

    // Push data ke stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " berhasil di-push ke stack" << endl;
    }

    // Pop data dari stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak bisa pop!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Pop data: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    // Tampilkan isi stack
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return;
        }
        cout << "Isi stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    // Push 3 angka
    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // tampilkan isi stack

    // Pop 1 angka
    s.pop();

    s.display(); // tampilkan isi stack setelah pop

    return 0;
}
