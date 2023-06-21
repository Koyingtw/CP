#include <iostream>
using namespace std;

int main() {
    int a, n, m;
    n = 1;
    cin >> a;
    for (int x = 1; x <= a; x++) {
        n = x;
        for (int y = 1; y <= x; y++) {
            m = y;
            cout << "*";
            if (n == m)
                cout << "\n";
        }
    }
    return 0;
}