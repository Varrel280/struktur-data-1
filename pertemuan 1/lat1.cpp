#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push data ke stack
    st.push(10);
    cout << "10 masuk ke stack." << endl;
    st.push(20);
    cout << "20 masuk ke stack." << endl;
    st.push(30);
    cout << "30 masuk ke stack." << endl;
    st.push(40);
    cout << "40 masuk ke stack." << endl;
    st.push(50);
    cout << "50 masuk ke stack." << endl;

    // Proses pop dengan while
    while (!st.empty()) {
        // Cetak isi stack
        stack<int> temp = st;
        cout << "Isi stack: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;

        // Pop elemen
        cout << st.top() << " keluar dari stack." << endl;
        st.pop();
    }

    cout << "Stack kosong!" << endl;

 return 0;
}