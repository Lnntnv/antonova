#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int farlongs;

    cout << "Enter the distance in the farlongs" << endl;
    cin >> farlongs;

    cout << "The Farlongs are equal in the yards (1 farlong = 220 yards): " << farlongs * 220 << endl;

    return 0;
}
