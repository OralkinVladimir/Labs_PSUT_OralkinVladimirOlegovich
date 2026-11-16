#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <clocale>
#include <windows.h>

using namespace std;

// ANSI цвета для колец
const string COLORS[] = {
    "\033[41m", // красный
    "\033[43m", // желтый
    "\033[42m", // зеленый
    "\033[46m", // голубой
    "\033[45m"  // фиолетовый
};
const string RESET = "\033[0m";

const int N = 5;  // количество колец

// Печать одной "строки" (уровня) для всех трёх стержней
void printLevel(const vector<vector<int>>& pegs, int level, int pegWidth) {
    for (int p = 0; p < 3; ++p) {
        string line;
        if (level < (int)pegs[p].size()) {
            int disk = pegs[p][level];
            int spaces = (pegWidth - (disk * 2 - 1)) / 2;
            line = string(spaces, ' ') +
                   COLORS[disk - 1] + string(disk * 2 - 1, '=') + RESET +
                   string(spaces, ' ');
        } else {
            line = string(pegWidth, ' ');
        }
        cout << line;
        if (p < 2) cout << " | ";
    }
    cout << "\n";
}

// Красивый вывод состояния башни
void printTowers(const vector<vector<int>>& pegs) {
    const int pegWidth = N * 2 + 1;
    const int height = N;

    cout << "\n";
    cout << string(pegWidth, '-') << " | "
         << string(pegWidth, '-') << " | "
         << string(pegWidth, '-') << "\n";

    for (int level = height - 1; level >= 0; --level)
        printLevel(pegs, level, pegWidth);

    cout << string(pegWidth, '-') << " | "
         << string(pegWidth, '-') << " | "
         << string(pegWidth, '-') << "\n";
    cout << setw(pegWidth) << "A" << "  |  "
         << setw(pegWidth) << "B" << "  |  "
         << setw(pegWidth) << "C" << "\n\n";
}

// Рекурсивное решение с визуализацией
void hanoi(int n, int from, int to, int aux,
           vector<vector<int>>& pegs,
           vector<string>& names,
           int& moveCount) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to, pegs, names, moveCount);

    int disk = pegs[from].back();
    pegs[from].pop_back();
    pegs[to].push_back(disk);
    moveCount++;

    cout << "Ход " << moveCount << ": кольцо " << disk
         << " : " << names[from] << " -> " << names[to] << "\n";
    printTowers(pegs);
    this_thread::sleep_for(chrono::milliseconds(400));

    hanoi(n - 1, aux, to, from, pegs, names, moveCount);
}

int main() {
    // ==== Локализация ====
    // Для корректного вывода русских букв в консоли Windows
    SetConsoleOutputCP(CP_UTF8);              // консоль в UTF-8
    SetConsoleCP(CP_UTF8);                    // ввод в UTF-8
    setlocale(LC_ALL, "ru_RU.UTF-8");         // локаль для функций C/C++
    // Запасной вариант, если ru_RU.UTF-8 недоступна:
    // setlocale(LC_ALL, "Russian");

    vector<vector<int>> pegs(3);
    for (int i = N; i >= 1; --i) pegs[0].push_back(i);

    vector<string> names = {"A", "B", "C"};
    int moveCount = 0;

    cout << "=== Ханойская башня (" << N << " колец) ===\n";
    cout << "Начальное состояние:\n";
    printTowers(pegs);
    this_thread::sleep_for(chrono::milliseconds(800));

    hanoi(N, 0, 2, 1, pegs, names, moveCount);

    cout << "Готово! Всего ходов: " << moveCount << "\n";
    return 0;
}