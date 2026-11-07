#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);   // корректный вывод кириллицы в консоли
    SetConsoleCP(65001);

    string s;
    cout << "Введите строку (не более 255 символов, в конце точка):\n";
    getline(cin, s);

    const int MAX_WORDS = 128;
    string words[MAX_WORDS];   // тексты цифровых слов
    int    pos[MAX_WORDS];     // их позиции в строке
    int    count = 0;

    int n = (int)s.size();

    // ---------- 1. Отбор слов, начинающихся с цифры ----------
    for (int i = 0; i < n; )
    {
        if (s[i] == ' ') { i++; continue; }   // пробел
        if (s[i] == '.') { i++; continue; }   // точка

        int start = i;
        while (i < n && s[i] != ' ' && s[i] != '.') i++;
        int end = i;

        if (s[start] >= '0' && s[start] <= '9')   // вместо isdigit
        {
            words[count] = s.substr(start, end - start);
            pos[count]   = start;
            count++;
        }
    }

    // ---------- 2. Сортировка по убыванию (пузырёк) ----------
    for (int a = 0; a < count - 1; a++)
        for (int b = 0; b < count - 1 - a; b++)
            if (words[b] < words[b + 1])
                swap(words[b], words[b + 1]);

    // ---------- 3. Сборка результата ----------
    string result;
    int k = 0;

    for (int i = 0; i < n; )
    {
        if (s[i] == ' ') { result += s[i++]; continue; }   // пробел
        if (s[i] == '.') { result += s[i++]; continue; }   // точка

        int start = i;
        while (i < n && s[i] != ' ' && s[i] != '.') i++;
        int end = i;

        if (k < count && pos[k] == start)
        {
            result += words[k];   // подставляем отсортированное слово
            k++;
        }
        else
        {
            result += s.substr(start, end - start);   // исходное слово
        }
    }

    cout << "\nРезультат:\n" << result << endl;
    return 0;
}   // 1a 2b 3c 10d.