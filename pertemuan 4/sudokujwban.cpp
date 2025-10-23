/*
Nama:Varrel Hutabarat
NIM: 241401031
TUGAS:Tenggat 12:59 wib dikumpulkan di github
*/

#include <iostream>      // Library untuk input-output standar
#include <vector>        // Library untuk menggunakan struktur data vektor
using namespace std;     // Agar tidak perlu menulis std:: setiap kali

// ============================================================
// FUNGSI UNTUK MENCETAK PAPAN SUDOKU
// ============================================================
void printBoard(const vector<vector<int>>& board) {
    // Loop untuk setiap baris
    for (int i = 0; i < 9; i++) {
        // Loop untuk setiap kolom
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";  // Cetak nilai pada posisi [i][j]

            // Setiap 3 kolom, beri spasi tambahan agar tampak seperti blok 3x3
            if ((j + 1) % 3 == 0)
                cout << " ";
        }

        cout << endl;  // Pindah ke baris berikutnya

        // Setiap 3 baris, beri baris kosong tambahan agar rapi
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

// ============================================================
// FUNGSI UNTUK MEMERIKSA APAKAH ANGKA VALID DI POSISI TERTENTU
// ============================================================
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        // Jika angka sudah ada di baris atau kolom yang sama, maka tidak valid
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Tentukan posisi awal dari kotak 3x3 tempat sel tersebut berada
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    // Periksa seluruh sel dalam kotak 3x3 tersebut
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Jika angka sudah ada dalam kotak 3x3, maka tidak valid
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    // Jika tidak ada konflik, berarti angka valid
    return true;
}

// ============================================================
// FUNGSI UTAMA UNTUK MENYELESAIKAN SUDOKU (DFS + BACKTRACKING)
// ============================================================
bool solveSudoku(vector<vector<int>>& board) {
    // Loop untuk mencari sel kosong (yang bernilai 0)
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Jika sel kosong ditemukan
            if (board[row][col] == 0) {

                // Coba isi dengan angka dari 1 sampai 9
                for (int num = 1; num <= 9; num++) {

                    // Periksa apakah angka valid di posisi ini
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;  // Masukkan angka ke papan

                        // Lanjutkan ke langkah berikutnya secara rekursif
                        if (solveSudoku(board))
                            return true;  // Jika berhasil, kembalikan true

                        // Jika gagal (tidak ada solusi di langkah berikutnya)
                        // maka kosongkan kembali sel ini (backtrack)
                        board[row][col] = 0;
                    }
                }

                // Jika tidak ada angka valid untuk sel ini, kembalikan false
                // agar program mundur ke langkah sebelumnya
                return false;
            }
        }
    }

    // Jika tidak ada sel kosong, berarti Sudoku sudah terpecahkan
    return true;
}

// ============================================================
// PROGRAM UTAMA
// ============================================================
int main() {
    // ========================================================
    // Nama : [Varrel Hutabarat]
    // NIM  : [241401031]

    // Inisialisasi papan Sudoku (0 = sel kosong)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Tampilkan papan Sudoku awal
    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    // Jalankan algoritma pemecahan Sudoku
    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;  // Akhiri program
}
