#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const int feetToInch = 12;
    const double inchToMeters = 0.0254;
    const double poundsToKg = 2.2;
    int inches;
    int feet;
    int pounds;
    double meters;
    double kg;

    cout << "Enter your height in feet: ";
    cin >> feet;

    cout << "Enter the growth residue in inches: ";
    cin >> inches;

    cout << "Enter your weight in pounds: ";
    cin >> pounds;

    inches = feet * feetToInch + inches;
    meters = inches * inchToMeters;
    kg = pounds / poundsToKg;

    cout << "IMT: " << kg / (meters*meters) << endl;

    return 0;
}
