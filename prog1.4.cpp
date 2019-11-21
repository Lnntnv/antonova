#include <iostream>

using namespace std;

double celsiusToPharyngeitis(double celsius) {
    return celsius * 1.8 + 32;
}

int main(int argc, char const *argv[])
{
    int celsius;

    cout << "Please enter a Celsius value: ";
    cin >> celsius;

    cout << "\n" << celsius << " degrees Celsius is " << celsiusToPharyngeitis(celsius) << " degrees Fahrenheit" << endl;
    return 0;
}
