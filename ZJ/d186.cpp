#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, x, y;
    while (cin >> a >> b) {
        x = sqrt(a);
        y = sqrt(b);
        if (a == 0 && b == 0)
            break;
        else if (a == 0 && b != 0)
            cout << y << endl;
        else if (x * x == a)
            cout << y - x + 1 << endl;
        else
            cout << y - x << endl;
    }
    return 0;
}