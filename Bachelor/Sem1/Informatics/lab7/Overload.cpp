#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <windows.h>

using namespace std;

// а) для массива целых чисел находит минимальный элемент
int findMin(int arr[], int n)
{
    int mn = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < mn) mn = arr[i];
    }
    return mn;
}

// б) для строки находит длину самого короткого слова
int findMin(const string& str)
{
    istringstream iss(str);
    string word;
    int minLen = INT_MAX;
    while (iss >> word)
    {
        if ((int)word.length() < minLen)
        {
            minLen = (int)word.length();
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ---------- Тест 1: массив целых чисел ----------
    cout << "==================================================\n";
    cout << "ТЕСТ 1. Перегрузка: вызов findMin(int[], int)\n";
    cout << "==================================================\n";

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите " << n << " целых чисел через пробел: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int minArr = findMin(arr, n);
    cout << "\nРезультат: минимальный элемент массива = " << minArr << "\n";
    cout << "Пояснение: компилятор выбрал версию findMin(int[], int),\n";
    cout << "потому что первый аргумент имеет тип int* (массив int),\n";
    cout << "а второй — int (количество элементов).\n\n";

    delete[] arr;

    // ---------- Тест 2: строка ----------
    cout << "==================================================\n";
    cout << "ТЕСТ 2. Перегрузка: вызов findMin(const string&)\n";
    cout << "==================================================\n";

    cin.ignore(); // очищаем буфер после ввода чисел
    cout << "Введите строку (слова разделяйте пробелами): ";
    string s;
    getline(cin, s);

    int minWord = findMin(s);
    cout << "\nРезультат: длина самого короткого слова = " << minWord << "\n";
    cout << "Пояснение: компилятор выбрал версию findMin(const string&),\n";
    cout << "потому что аргумент имеет тип string, а не массив int.\n";
    cout << "Это и есть перегрузка: одно имя — разные типы параметров.\n";

    return 0;
}