#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int x0, int length)
{
    return x0 + rand() % length;
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    int n;
    int m;
    int **arr;
    cout << "Введите длину колонки матрицы: ";
    cin >> n;
    cout << "Введите длину строки матрицы: ";
    cin >> m;

    arr = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = random(0, 3);
        }
    }

    cout << "Сгенерированный массив:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    int count_column_with_zero = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[j][i] == 0)
            {
                count_column_with_zero++;
                break;
            }
        }
    }
    cout << "Кол-во колонок имеющие нулевые элементы: " << count_column_with_zero << "\n";

    int max_sequence = 1;
    int max_index = -1;
    for (int i = 0; i < n; ++i)
    {
        int max = 1;
        for (int j = 0; j < m - 1; ++j)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                max++;
                if (max > max_sequence)
                {
                    max_sequence = max;
                    max_index = i;
                }
            }
            else
            {
                if (max > max_sequence)
                {
                    max_sequence = max;
                    max_index = i;
                }
                max = 1;
            }
        }
    }

    if (max_index == -1)
    {
        cout << "Нет последовательностей";
    }
    else
    {
        cout << "Индекс строки с максимальной последовательностью одинаковых чисел: " << max_index << " (" << max_index+1 << " номер)";
    }

    cout << endl;
    return 0;
}
