#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");

    int n;
    cout << "Введите количество строк n: ";   // вывод: запрос размера
    cin >> n;                                  // ввод: размер массива

    char** mass = new char*[n];                // new: массив указателей
    char buf[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите строку " << i + 1 << ": ";   // вывод: запрос строки
        cin >> buf;                                    // ввод: строка с клавиатуры

        mass[i] = new char[strlen(buf) + 1];           // new: память под строку
        strcpy(mass[i], buf);                          // копирование строки
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int len = strlen(mass[i]);
        if (len > 0 && mass[i][0] == 'a' && mass[i][len - 1] == 'a')
            delete[] mass[i];                 // delete: удаляем подходящую строку
        else
            mass[k++] = mass[i];              // уплотняем оставшиеся строки
    }
    n = k;

    cout << "\nРезультат:\n";                 // вывод: заголовок результата
    for (int i = 0; i < n; i++)
        cout << mass[i] << endl;              // вывод: строка результата

    for (int i = 0; i < n; i++)
        delete[] mass[i];                     // delete: освобождаем строки
    delete[] mass;                            // delete: освобождаем массив указателей

    return 0;
}