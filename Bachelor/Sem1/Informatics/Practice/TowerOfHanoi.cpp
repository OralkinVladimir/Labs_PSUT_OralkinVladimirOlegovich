#include <iostream>
#include <windows.h>

using namespace std;

const int N = 5;
const int W = N * 2;

int pegs[3][N];
int h[3];
int moves = 0;

void drawTowers()
{
    for (int level = N - 1; level >= 0; --level)
    {
        for (int p = 0; p < 3; ++p)
        {
            if (level < h[p])
            {
                int d = pegs[p][level];
                int len = d * 2;
                int pad = (W - len) / 2;
                for (int i = 0; i < pad; ++i) cout << ' ';
                for (int i = 0; i < len; ++i) cout << '*';
                for (int i = 0; i < pad; ++i) cout << ' ';
            }
            else
            {
                for (int i = 0; i < W; ++i) cout << ' ';
            }
            if (p < 2) cout << " | ";
        }
        cout << "\n";
    }
    cout << "   A    |    B    |    C\n";
    cout << "------------------------\n";
}

void hanoi(int n, int from, int to, int aux)
{
    if (n == 0) return;

    hanoi(n - 1, from, aux, to);

    pegs[to][h[to]++] = pegs[from][--h[from]];
    moves++;

    system("cls");
    cout << "Ход " << moves << ": кольцо " << pegs[to][h[to] - 1]
         << " : " << (char)('A' + from) << " -> " << (char)('A' + to) << "\n\n";
    drawTowers();
    Sleep(600);

    hanoi(n - 1, aux, to, from);
}

int main()
{
    SetConsoleOutputCP(65001);

    h[0] = h[1] = h[2] = 0;
    for (int i = 0; i < N; ++i) pegs[0][h[0]++] = N - i;

    system("cls");
    cout << "Ханойская башня (5 колец)\n\n";
    drawTowers();
    Sleep(1500);

    hanoi(N, 0, 2, 1);

    cout << "\nГотово! Ходов: " << moves << "\n";
    return 0;
}