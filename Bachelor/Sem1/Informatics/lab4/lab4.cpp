#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

// Функция для вывода массива как "кольца" справа налево
// (от текущего элемента к предыдущему, с переходом от 1-го к последнему)
void printRingReverse(int arr[], int n, int startIndex) {
    if (n == 0) {
        cout << "Массив пуст." << endl;
        return;
    }
    cout << "Вывод (справа налево, начиная с индекса " << startIndex << "): ";
    int current = startIndex;
    for (int i = 0; i < n; ++i) {
        cout << arr[current] << " ";
        // Переход к предыдущему элементу по кольцу
        current = (current - 1 + n) % n;
    }
    cout << endl;
}

// Функция для удаления нечетных элементов
int removeOddElements(int arr[], int n) {
    int newN = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) { // Если элемент четный
            arr[newN] = arr[i];
            newN++;
        }
    }
    return newN;
}

int main()
{
    setlocale(LC_ALL, ".UTF8");
    srand(42); // фиксированное зерно для воспроизводимости

    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n;

    // Ввод размера массива
    cout << "Введите размер массива (не более " << MAX_SIZE << "): ";
    cin >> n;
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Некорректный размер." << endl;
        return 1;
    }

    // 1. Формирование массива (датчик случайных чисел)
    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 - 50; // Случайные числа от -50 до 49
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ввод K
    int K;
    cout << "Введите K (индекс начального элемента): ";
    cin >> K;
    if (K < 0 || K >= n) {
        cout << "Индекс K вне диапазона. Корректируем на 0." << endl;
        K = 0;
    }

    // 2. Распечатать массив, начиная с K-го и до K+1 (по кольцу справа налево)
    printRingReverse(arr, n, K);

    // 3. Добавить в кольцо первый и последний элементы
    if (n + 2 <= MAX_SIZE) {
        int firstElem = arr[0];
        int lastElem = arr[n - 1];

        // Сдвигаем элементы вправо, чтобы освободить место в начале
        for (int i = n + 1; i > 0; --i) {
            arr[i] = arr[i - 2];
        }
        // Вставляем копии первого и последнего элементов
        arr[0] = firstElem;
        arr[1] = lastElem;
        n += 2;

        cout << "\nМассив после добавления первого и последнего элементов: ";
        for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << endl;
    } else {
        cout << "\nНедостаточно места для добавления элементов." << endl;
    }

    // 4. Удалить из кольца нечетные элементы
    n = removeOddElements(arr, n);
    cout << "\nМассив после удаления нечетных элементов: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;

    // 5. Распечатать полученный массив, начиная с K-го элемента и до K+1
    if (n == 0) {
        cout << "Массив пуст после удаления." << endl;
    } else {
        if (K >= n) {
            K = K % n; // Корректировка индекса
        }
        printRingReverse(arr, n, K);
    }

    return 0;
}