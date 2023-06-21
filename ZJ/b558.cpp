#include <iostream>

using namespace std;

int n, a[505];

int main() {
    a[1] = 1;
    while (cin >> n) {
        for (int i = 2; i <= n; i++)
            a[i] = a[i - 1] + i - 1;
        cout << a[n] << endl;
    }
    return 0;
}