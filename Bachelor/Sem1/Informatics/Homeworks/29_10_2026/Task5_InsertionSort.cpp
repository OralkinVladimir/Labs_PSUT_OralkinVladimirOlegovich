#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    const int n = 7;
    int a[n] = {45, 12, 89, 3, 56, 23, 78};

    for (int i = 1; i < n; i++) {
        int key = a[i]; 
        int j = i - 1;
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "Отсортированный массив (вставка): ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}