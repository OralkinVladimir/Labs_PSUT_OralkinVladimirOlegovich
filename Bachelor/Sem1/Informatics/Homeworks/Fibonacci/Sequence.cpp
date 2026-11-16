#include <iostream>
using namespace std;

// Хвостовая рекурсия с аккумулятором
unsigned long long fib(unsigned n, unsigned long long a = 0, unsigned long long b = 1)
{
    if (n == 0) return a;
    return fib(n - 1, b, a + b);
}

int main()
{
    for (unsigned i = 0; i < 20; ++i)
        cout << fib(i) << ' ';
    cout << '\n';
    return 0;
}