#include <iostream>

using namespace std;

int main()
{
    int a, n;
    cin >> a;
    if (a == 0)
        cout << 0 << endl;
    while (a >= 1) {
        if (a % 10 != 0) {
            while (a >= 1) {
                cout << a % 10;
                a = a / 10;
            }
        }
        else
            a = a / 10;
    }

    return 0;
}