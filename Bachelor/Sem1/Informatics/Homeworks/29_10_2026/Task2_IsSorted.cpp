#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");

    const int n = 6;
    int a[n] = {2, 4, 5, 7, 8, 9};
    
    bool isSorted = true;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "Массив упорядочен по возрастанию." << endl;
    } else {
        cout << "Массив НЕ упорядочен по возрастанию." << endl;
    }

    return 0;
}