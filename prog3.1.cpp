#include <iostream>

using namespace std;

double func(double a, double b, double c, double x)
{
    if (a < 0 && c != 0)
    {
        return a * x * x + b * x + c;
    }
    else if (a > c && c == 0)
    {
        return (-a) / (x - c);
    }
    else
    {
        return a * (x + c);
    }
}

double func(int a, int b, int c, int x)
{
    if (a < 0 && c != 0)
    {
        return a * x * x + b * x + c;
    }
    else if (a > c && c == 0)
    {
        return (-a) / (x - c);
    }
    else
    {
        return a * (x + c);
    }
}

int main(int argc, char const *argv[])
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    double dx;

    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    cout << "Введите c: ";
    cin >> c;

    cout << "Введите x1: ";
    cin >> x1;

    cout << "Введите x2: ";
    cin >> x2;

    cout << "Введите dx: ";
    cin >> dx;

    cout << 'x' << "\t\t"
         << "значение функции\n";
    if ((int)a & ((int)b | (int)c) != 0)
    {
        for (double x = x1; x < x2; x += dx)
        {
            if (x < 0.00001 && x > -0.00001) // иначе -5.55112e-17
            {
                cout << 0 << "\t\t" << func(a, b, c, x) << '\n';
            }
            else
            {
                cout << x << "\t\t" << func(a, b, c, x) << '\n';
            }
        }
    }
    else
    {
        for (double x = x1; x < x2; x += dx)
        {
            if (x < 0.00001 && x > -0.00001) // иначе -5.55112e-17
            {
                cout << 0 << "\t\t" << func((int)a, (int)b, (int)c, (int)x) << '\n';
            }
            else
            {
                cout << x << "\t\t" << func((int)a, (int)b, (int)c, (int)x) << '\n';
            }
        }
    }

    return 0;
}
