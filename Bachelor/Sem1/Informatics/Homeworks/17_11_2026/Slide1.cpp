#include <iostream>
#include <clocale>

using namespace std;

int main()
 {
    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Создание динамического массива
    int* arr = new int[n];

    // Ввод элементов с клавиатуры (вместо случайных чисел)
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Вывод массива на экран
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Нахождение суммы
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Сумма: " << sum << endl;

    // Освобождение памяти
    delete[] arr;

    return 0;
}