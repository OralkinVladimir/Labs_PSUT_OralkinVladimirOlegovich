#include <iostream>
#include <clocale>
using namespace std;

int main()
 {
    setlocale(LC_ALL, ".UTF8");
    // Строка 8: здесь ОБЯЗАТЕЛЬНО нужна точка с запятой в конце!
    const int n = 10; 
    
    // Строка 9 и 10: здесь объявление массива
    int a[n] = {4, 9, 2, 9, 1, 5, 9, 1, 8, 1}; 

    // Инициализация максимума и минимума первым элементом
    int max_val = a[0];
    int min_val = a[0];
    int max_idx = 0;
    int min_idx = 0;
    int count_max = 0;
    int count_min = 0;

    // Проход по массиву для поиска значений и их первых индексов
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
        if (a[i] < min_val) {
            min_val = a[i];
            min_idx = i;
        }
    }

    // Второй проход для подсчета количества вхождений
    for (int i = 0; i < n; i++) {
        if (a[i] == max_val) count_max++;
        if (a[i] == min_val) count_min++;
    }

    cout << "Максимальный элемент: " << max_val << ", его первый индекс: " << max_idx << endl;
    cout << "Минимальный элемент: " << min_val << ", его первый индекс: " << min_idx << endl;
    cout << "Количество максимальных элементов: " << count_max << endl;
    cout << "Количество минимальных элементов: " << count_min << endl;

    return 0;
}