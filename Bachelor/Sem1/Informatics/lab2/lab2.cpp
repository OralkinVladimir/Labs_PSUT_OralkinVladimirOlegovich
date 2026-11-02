#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");
    
    double eps = 1e-4;
    double an = 2.0;
    double sum = 0.0;
    int n = 2;

    while (an >= eps) {
        sum += an;
        an = an * (n + 1) * (n - 1) * (n - 1) / (n * n * n);
        n++;
    }

    cout << "Сумма ряда с точностью eps = " << eps << " равна: " << sum << endl;
    
    return 0;
}