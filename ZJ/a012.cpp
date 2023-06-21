#include <iostream>

using namespace std;

int main() {
    long long a, b;
    while (cin >> a >> b) {
        long long ans = a - b;
        if (ans < 0)
            ans = -ans;
        cout << ans << endl;
    }
    return 0;
}