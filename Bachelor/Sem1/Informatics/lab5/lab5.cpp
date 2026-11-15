#include <iostream>
#include <string>
#include <clocale> // 

using namespace std;

// Функция проверяет, можно ли перестановкой строк матрицы NxN
// сделать первый столбец строго возрастающим.
// Массив передаётся в функцию как параметр.
bool canMakeFirstColumnIncreasing(int n, int matrix[][100])
{
    // Попарно сравниваем элементы первого столбца.
    // Если есть совпадение — строгое возрастание невозможно.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][0] == matrix[j][0])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 

    string s;
    int n;

    cout << "Enter N: ";
    cin >> n;
    
    cout << "Enter string of " << n * n << " digits: ";
    cin >> s;

    // Проверка длины строки
    if (s.length() != n * n)
    {
        cout << "Error: string length must be N*N = " << n * n << endl;
        return 1;
    }

    // Формируем матрицу NxN: подстрока длиной N -> строка матрицы
    int matrix[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = s[i * n + j] - '0'; // Преобразуем символ в число
        }
    }

    // Вывод исходной матрицы
    cout << "\nSource matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Проверка и вывод результата
    if (canMakeFirstColumnIncreasing(n, matrix))
    {
        cout << "\nResult: YES. It is possible to sort the first column in ascending order." << endl;
    }
    else
    {
        cout << "\nResult: NO. There are duplicate first elements, strict ascending order is impossible." << endl;
    }

    return 0;
}