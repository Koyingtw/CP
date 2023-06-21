#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;


    if (b * b - 4 * a * c < 0)
        cout << "No real root" << endl;
    else {
        int x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        int x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (x1 < x2)
            swap(x1, x2);

        if (b * b - 4 * a * c == 0)
            cout << "Two same roots x=" << x1 << endl;
        else
            cout << "Two different roots x1=" << x1 << " , x2=" << x2 << endl;
    }
    return 0;
}