#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    const int n = 7;
    int a[n] = {45, 12, 89, 3, 56, 23, 78};

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }

    cout << "Отсортированный массив (выбор): ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}