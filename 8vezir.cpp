#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8  // 8 vezir problemi

int board[N];    // board[col] = row
int solutionCount = 0;

// Bu fonksiyon þu ana kadar yerleþtirilmiþ vezirlerle çakýþma var mý diye bakar
int isSafe(int col, int row) {
    for (int prevCol = 0; prevCol < col; prevCol++) {
        int prevRow = board[prevCol];

        // 1) Ayný satýr?
        if (prevRow == row)
            return 0;

        // 2) Ayný çapraz? |row - prevRow| == |col - prevCol|
        if (abs(prevRow - row) == abs(prevCol - col))
            return 0;
    }
    return 1; // sorun yoksa güvenli
}

// Tahtayý yazdýr (görsel olarak)
void printBoard() {
    printf("Çözüm %d:\n", ++solutionCount);
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

// Backtracking fonksiyonu: her sütuna bir vezir koymayý dener
void solve(int col) {
    // Tüm sütunlara yerleþtirdiysek çözüm bulduk
    if (col == N) {
        printBoard();
        return;
    }

    // Bu sütun için tüm satýrlarý dene
    for (int row = 0; row < N; row++) {
        if (isSafe(col, row)) {
            board[col] = row;   // veziri koy
            solve(col + 1);     // sonraki sütuna geç
            // backtracking: baþka satýrlarý denemek için geri dön
        }
    }
}

int main() {
    solve(0);

    printf("Toplam çözüm sayýsý: %d\n", solutionCount);
    return 0;
}

