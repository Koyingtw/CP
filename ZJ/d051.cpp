#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double f;
    cin >> f;
    cout << setprecision(3) << fixed << (f - 32) * 5.0 / 9.0 << endl;
    return 0;
}