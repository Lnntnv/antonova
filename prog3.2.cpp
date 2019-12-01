#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Введите кол-во элементов в массиве: ";
    cin >> n;
    cout << "Введите элементы" << endl;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if ((!(arr[j - 1] >= 0)) && (arr[j] >= 0))
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }

    cout << " Отсортированный массив:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int multiply = 1;
    for (int i = 0; i < n; i += 2)
    {
        multiply *= arr[i];
    }
    cout << "Произведение элементов находящихся на четных индексах: " << multiply << endl;

    int first_index = 0;
    int second_index = n - 1;
    int sum_between_zero = 0;
    while (first_index != second_index)
    {
        if (arr[first_index] != 0)
        {
            first_index++;
        }
        if (arr[second_index] != 0)
        {
            second_index--;
        }
        if (arr[first_index] == 0 && arr[second_index] == 0)
        {
            break;
        }
    }

    if (arr[first_index] == 0 && arr[second_index] == 0)
    {
        for (int i = first_index + 1; i < second_index; ++i)
        {
            sum_between_zero += arr[i];
        }
        cout << "Сумма между нулевыми элементами: " << sum_between_zero << endl;
    }
    else
    {
        cout << "В массиве нет нулевых элеметов или он один" << endl;
    }

    return 0;
}
