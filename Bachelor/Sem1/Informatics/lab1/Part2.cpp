#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");

    cout << "========================================" << endl;
    cout << "ЗАДАНИЕ 2. НАЧАЛЬНЫЕ ЗНАЧЕНИЯ: n = 5, m = 3" << endl;
    cout << "========================================" << endl << endl;

    // Выражение 1
    {
        int n = 5, m = 3;
        cout << "1) Выражение: - -m-++n" << endl;
        cout << "   До:    n = " << n << ", m = " << m << endl;
        int res = - -m - ++n;
        cout << "   Результат = " << res << endl;
        cout << "   После: n = " << n << ", m = " << m << endl << endl;
    }

    // Выражение 2
    {
        int n = 5, m = 3;
        cout << "2) Выражение: m*n < n++" << endl;
        cout << "   До:    n = " << n << ", m = " << m << endl;
        int res = m * n < n++;
        cout << "   Результат = " << res << endl;
        cout << "   После: n = " << n << ", m = " << m << endl << endl;
    }

    // Выражение 3
    {
        int n = 5, m = 3;
        cout << "3) Выражение: n-- > m++" << endl;
        cout << "   До:    n = " << n << ", m = " << m << endl;
        int res = n-- > m++;
        cout << "   Результат = " << res << endl;
        cout << "   После: n = " << n << ", m = " << m << endl << endl;
    }

    return 0;
}