#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const double inchToFeet = 0.08334;
    double gallons;
    double miles;

    cout << "Enter how many gallons of fuel the car used up: ";
    cin >> gallons;

    cout << "Enter how many miles the car has driven: ";
    cin >> miles;

    cout << "Miles per gallon: " << miles/gallons << endl;

    return 0;
}
