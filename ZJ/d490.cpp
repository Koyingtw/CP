#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            ans += i;
        }
    }

    int n = 5;
    while (n--) {
        cout << n << endl;
    }

    cout << ans << endl;
}