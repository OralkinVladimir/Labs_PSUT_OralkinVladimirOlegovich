#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    const int n = 7;
    int a[n] = {45, 12, 89, 3, 56, 23, 78};

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Отсортированный массив (пузырек): ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}