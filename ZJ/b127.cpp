#include <iostream>

using namespace std;

int main() {
    int ans[50];
    ans[0] = ans[1] = 1;

    for (int i = 2; i <= 45; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }

    return 0;
}