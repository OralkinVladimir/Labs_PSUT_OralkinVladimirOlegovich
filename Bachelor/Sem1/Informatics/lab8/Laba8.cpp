#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>
using namespace std;

struct Film
{
    char title[60], director[60], country[60];
    float profit;
};

void inputFilm(Film &f)
{
    cin.getline(f.title, 60);
    cin.getline(f.director, 60);
    cin.getline(f.country, 60);
    cin >> f.profit;
    cin.ignore();
}

void createFile(const char *name)
{
    FILE *f = fopen(name, "wb");
    if (!f) { perror(name); return; }

    int n;
    cout << "N (>=5): ";
    cin >> n;
    cin.ignore();
    if (n < 5) { cout << "Need >=5" << endl; fclose(f); return; }

    for (int i = 0; i < n; i++)
    {
        Film x;
        inputFilm(x);
        if (fwrite(&x, sizeof(Film), 1, f) != 1) perror("write");
    }
    fclose(f);
}

void printFile(const char *name)
{
    FILE *f = fopen(name, "rb");
    if (!f) { perror(name); return; }

    Film x;
    int i = 1;
    while (fread(&x, sizeof(Film), 1, f) == 1)
        cout << i++ << ": " << x.title << " | " << x.director
             << " | " << x.country << " | " << x.profit << endl;
    if (ferror(f)) perror("read");
    fclose(f);
}

void deleteLast(const char *name, int k)
{
    FILE *f = fopen(name, "rb");
    if (!f) { perror(name); return; }
    fseek(f, 0, SEEK_END);
    int total = ftell(f) / sizeof(Film);
    fseek(f, 0, SEEK_SET);

    FILE *t = fopen("tmp.dat", "wb");
    if (!t) { perror("tmp.dat"); fclose(f); return; }

    Film x;
    for (int i = 0; i < total - k; i++)
    {
        if (fread(&x, sizeof(Film), 1, f) != 1) { perror("read"); break; }
        if (fwrite(&x, sizeof(Film), 1, t) != 1) { perror("write"); break; }
    }
    fclose(f);
    fclose(t);
    remove(name);
    rename("tmp.dat", name);
}

void addAfter(const char *name, const char *title)
{
    FILE *f = fopen(name, "rb");
    if (!f) { perror(name); return; }
    FILE *t = fopen("tmp.dat", "wb");
    if (!t) { perror("tmp.dat"); fclose(f); return; }

    Film x;
    int found = 0;
    while (fread(&x, sizeof(Film), 1, f) == 1)
    {
        if (fwrite(&x, sizeof(Film), 1, t) != 1) { perror("write"); break; }
        if (!found && strcmp(x.title, title) == 0)
        {
            found = 1;
            Film y;
            inputFilm(y);
            if (fwrite(&y, sizeof(Film), 1, t) != 1) perror("write");
        }
    }
    fclose(f);
    fclose(t);

    if (!found)
        cout << "Not found" << endl;
    else
    {
        remove(name);
        rename("tmp.dat", name);
        cout << "Added after " << title << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char s[60];

    createFile("f.dat");
    printFile("f.dat");

    deleteLast("f.dat", 2);
    cout << "\nAfter delete:" << endl;
    printFile("f.dat");

    cout << "\nAfter which title: ";
    cin.getline(s, 60);
    addAfter("f.dat", s);
    cout << "\nAfter add:" << endl;
    printFile("f.dat");

    return 0;
}