#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const double inchToFeet = 0.08334;
    int inches;
    int feet;

    cout << "Enter your height in inches: ";
    cin >> inches;

    feet = inches * inchToFeet;
    inches -= feet * 12;

    cout << "Feets: " << feet << "; Inch: " << inches << endl;

    return 0;
}
