#include <iostream>
#include <string>
#include <cctype>   // toupper

using namespace std;

// Convierte letra A..H a columna 1..8
int colOf(char ch) {
    ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
    if (ch < 'A' || ch > 'H') return -1;
    return (ch - 'A') + 1;
}

// Convierte dígito '1'..'8' a fila 1..8
int rowOf(char ch) {
    if (ch < '1' || ch > '8') return -1;
    return (ch - '0');
}

bool in(int r, int c) { return r >= 1 && r <= 8 && c >= 1 && c <= 8; }

// ¿La torre (tr,tc) ve (qr,qc) sin que la bloquee la otra torre (orr,orc)?
bool rookSees(int tr, int tc, bool alive,
    int orr, int orc, bool otherAlive,
    int qr, int qc)
{
    if (!alive) return false;

    if (tr == qr) { // misma fila
        int step = (qc > tc) ? 1 : -1;
        for (int c = tc + step; c != qc; c += step) {
            if (otherAlive && orr == tr && orc == c) return false; // bloquea
        }
        return true;
    }
    if (tc == qc) { // misma columna
        int step = (qr > tr) ? 1 : -1;
        for (int r = tr + step; r != qr; r += step) {
            if (otherAlive && orc == tc && orr == r) return false;
        }
        return true;
    }
    return false;
}

// Lee una posición tipo "B2" y la guarda en r,c
void readPos(const string& who, int& r, int& c) {
    while (true) {
        cout << "Posicion de " << who << " (ej. B2): ";
        string s; cin >> s;
        if (!cin) { r = c = -1; return; }
        if (s.size() < 2) { cout << "Formato invalido\n"; continue; }
        c = colOf(s[0]);
        r = rowOf(s[1]);
        if (c == -1 || r == -1) { cout << "Rango A-H / 1-8\n"; continue; }
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r1, c1, r2, c2, rq, cq;
    bool validado = true;
    do {
    readPos("Torre 1", r1, c1);
    readPos("Torre 2", r2, c2);
    readPos("Reina", rq, cq);

    if ((r1 == r2 && c1 == c2) || (rq == r1 && cq == c1) || (rq == r2 && cq == c2)) {
        cout << "Posiciones invalidas (solapadas).\n";
        return validado = false;
    }
    }while(validado=false );

    // Tablero
    char B[9][9];
    for (int i = 1;i <= 8;i++) for (int j = 1;j <= 8;j++) B[i][j] = '.';

    B[r1][c1] = 'T'; B[r2][c2] = 'T'; B[rq][cq] = 'R';

    // Direcciones de la reina
    int dr[8] = { 1,-1, 0, 0, 1, 1,-1,-1 };
    int dc[8] = { 0, 0, 1,-1, 1,-1, 1,-1 };

    for (int k = 0;k < 8;k++) {
        int r = rq + dr[k], c = cq + dc[k];
        while (in(r, c)) {
            bool hitsT1 = (r == r1 && c == c1);
            bool hitsT2 = (r == r2 && c == c2);

            bool t1Alive = !hitsT1;
            bool t2Alive = !hitsT2;

            bool atk = rookSees(r1, c1, t1Alive, r2, c2, t2Alive, r, c)
                || rookSees(r2, c2, t2Alive, r1, c1, t1Alive, r, c);

            B[r][c] = atk ? 'X' : 'V';

            if (hitsT1 || hitsT2) break; // capturó; no sigue
            r += dr[k]; c += dc[k];
        }
    }

    // Imprimir tablero
    cout << "\n    A B C D E F G H\n";
    cout << "   -----------------\n";
    for (int i = 1;i <= 8;i++) {
        cout << i << " | ";
        for (int j = 1;j <= 8;j++) cout << B[i][j] << ' ';
        cout << "|\n";
    }
    cout << "   -----------------\n";
    cout << "Leyenda: R=Reina  T=Torre  V=seguro  X=en jaque\n";
    return 0;
}
