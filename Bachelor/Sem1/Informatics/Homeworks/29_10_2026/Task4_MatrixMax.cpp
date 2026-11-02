#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols] = {
        {5, 12, 3, 8},
        {9, 25, 1, 4},
        {7, 6, 11, 2}
    };

    int max_val = matrix[0][0];
    int max_row = 0;
    int max_col = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "Максимальный элемент: " << max_val << endl;
    cout << "Его индексы: строка " << max_row << ", столбец " << max_col << endl;

    return 0;
}