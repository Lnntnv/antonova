#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct scan_info
{
    char model[25];
    int price;
    double x_size;
    double y_size;
    int optr;
    int grey;
};

void read_to_scan(char *file_name)
{
    FILE *f = fopen(file_name, "rb");
    int n;
    fread(&n, sizeof(n), 1, f);
    cout << "Кол-во записей: " << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        scan_info info;
        fread(&info, sizeof(info), 1, f);
        cout << info.model << ' ' << info.price << ' ' << info.x_size << ' ' << info.y_size << ' ' << info.optr << ' ' << info.optr << '\n';
    }
    fclose(f);
}

void sort(scan_info *obj, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (strcmp(obj[j].model, obj[j + 1].model) > 0)
            {
                swap(obj[j], obj[j + 1]);
            }
        }
    }
}

void create_file(char *file_name)
{
    int n;
    scan_info *infos;
    FILE *f = fopen(file_name, "wb+");

    cout << "Введите число записей: ";
    cin >> n;
    infos = new scan_info[n];

    for (int i = 0; i < n; ++i)
    {
        scan_info info;
        cout << "Запись " << i + 1 << '\n';

        cout << "Введите название модели: ";
        cin >> info.model;

        cout << "Введите цену: ";
        cin >> info.price;

        cout << "Введите горизонтальный размер области сканирования: ";
        cin >> info.x_size;

        cout << "Введите вертикальный размер области сканирования: ";
        cin >> info.y_size;

        cout << "Введите оптическое разрешение: ";
        cin >> info.optr;

        cout << "Введите число градаций серого: ";
        cin >> info.grey;
        infos[i] = info;
    }
    sort(infos, n);
    fwrite(&n, sizeof(n), 1, f);
    for (int i = 0; i < n; ++i)
    {
        fwrite(&infos[i], sizeof(infos[i]), 1, f);
    }
    fclose(f);
}

int main(int argc, char const *argv[])
{
    create_file("filename");
    cout << endl;
    read_to_scan("filename");
    return 0;
}
