#include <iostream>
#include <clocale>

using namespace std;

int main() 
{
    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // 1. Создание динамического массива
    int* arr = new int[n];

    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i); // Использование арифметики указателей
    }

    // 2 и 3. Обработка (используем копию, так как нужно старое значение)
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        *(temp + i) = *(arr + i);
    }

    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            if (i == 0 || i == n - 1) {
                *(arr + i) = 0; // Первый или последний
            } else {
                *(arr + i) = *(temp + i - 1) + *(temp + i + 1); // Сумма соседей
            }
        }
    }

    // 4. Вывод
    cout << "Результат: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // 5. Освобождение памяти
    delete[] arr;
    delete[] temp;

    return 0;
}