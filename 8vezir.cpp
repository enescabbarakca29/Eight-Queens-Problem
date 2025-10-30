#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8  // 8 vezir problemi

int board[N];    // board[col] = row
int solutionCount = 0;

// Bu fonksiyon �u ana kadar yerle�tirilmi� vezirlerle �ak��ma var m� diye bakar
int isSafe(int col, int row) {
    for (int prevCol = 0; prevCol < col; prevCol++) {
        int prevRow = board[prevCol];

        // 1) Ayn� sat�r?
        if (prevRow == row)
            return 0;

        // 2) Ayn� �apraz? |row - prevRow| == |col - prevCol|
        if (abs(prevRow - row) == abs(prevCol - col))
            return 0;
    }
    return 1; // sorun yoksa g�venli
}

// Tahtay� yazd�r (g�rsel olarak)
void printBoard() {
    printf("��z�m %d:\n", ++solutionCount);
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[col] == row)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Backtracking fonksiyonu: her s�tuna bir vezir koymay� dener
void solve(int col) {
    // T�m s�tunlara yerle�tirdiysek ��z�m bulduk
    if (col == N) {
        printBoard();
        return;
    }

    // Bu s�tun i�in t�m sat�rlar� dene
    for (int row = 0; row < N; row++) {
        if (isSafe(col, row)) {
            board[col] = row;   // veziri koy
            solve(col + 1);     // sonraki s�tuna ge�
            // backtracking: ba�ka sat�rlar� denemek i�in geri d�n
        }
    }
}

int main() {
    solve(0);

    printf("Toplam ��z�m say�s�: %d\n", solutionCount);
    return 0;
}

