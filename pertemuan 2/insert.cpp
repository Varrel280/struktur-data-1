#include <iostream>
using namespace std;

// deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert di depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    } 
}

// insert di belakang
void insertLast (int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// insert ddengan nilai tertentu
void insertAfter(int n, int check) {
    if(head == NULL) {
        cout << "List kosong. insert didepan dulu\n";
        
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;
    while(p != NULL && p -> value != check) {
        p = p -> next;

        if (p == NULL) {
            cout << "Node  dengan nilai " << check << "tidak dtemukan\n;";
            delete newNode;
            } else {
                newNode -> next = p -> next;
                p -> next = newNode;
                if (p == tail) {
                    tail = newNode;
                }
        }
    } 
}

// cetak linked List

void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}