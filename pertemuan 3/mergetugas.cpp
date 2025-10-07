#include <iostream>     // Library untuk input dan output (cout, cin)
#include <vector>       // Library untuk menggunakan struktur data vector
using namespace std;    // Agar tidak perlu menulis std:: di setiap penggunaan

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;   // Jumlah elemen di bagian kiri
    int n2 = right - mid;      // Jumlah elemen di bagian kanan

    vector<int> L(n1), R(n2);  // Membuat dua vector sementara: L untuk kiri, R untuk kanan

    // Menyalin data dari arr ke vector L
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Menyalin data dari arr ke vector R
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;   // Indeks awal untuk L
    int j = 0;   // Indeks awal untuk R
    int k = left; // Indeks awal untuk array utama arr

    // Menggabungkan kembali dua array (L dan R) ke dalam arr secara terurut
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {     // Jika elemen di L lebih kecil atau sama
            arr[k] = L[i];      // Masukkan elemen dari L ke arr
            i++;                // Pindah ke elemen berikutnya di L
        } else {
            arr[k] = R[j];      // Masukkan elemen dari R ke arr
            j++;                // Pindah ke elemen berikutnya di R
        }
        k++;                    // Pindah ke posisi berikutnya di arr
    }

    // Menyalin sisa elemen di L (jika masih ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Menyalin sisa elemen di R (jika masih ada)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort (rekursif)
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right)  // Kondisi dasar: jika hanya 1 elemen, tidak perlu diurutkan
        return;

    int mid = left + (right - left) / 2;  // Menentukan titik tengah array

    mergeSort(arr, left, mid);       // Mengurutkan bagian kiri
    mergeSort(arr, mid + 1, right);  // Mengurutkan bagian kanan
   
    merge(arr, left, mid, right);    // Menggabungkan dua bagian yang sudah diurutkan
}

// Fungsi untuk mencetak isi array ke layar
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) { // Loop untuk setiap elemen
        cout << arr[i] << " ";             // Cetak elemen dengan spasi
    }
    cout << endl;                          // Pindah ke baris baru
}

int main() {
    int n;  // Variabel untuk menyimpan jumlah elemen
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;  // Input jumlah elemen
   
    vector<int> data(n);  // Membuat vector 'data' dengan ukuran n
    cout << "Masukkan elemen-elemen data: \n ";
    for (int i = 0; i < n; i++) {   // Input setiap elemen dari pengguna
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);   // Menampilkan array sebelum diurutkan
   
    mergeSort(data, 0, n - 1);  // Memanggil fungsi merge sort
   
    cout << "Array setelah diurutkan: ";
    printArray(data);   // Menampilkan array setelah diurutkan
   
    return 0;  // Program selesai
}
