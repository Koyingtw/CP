#include <iostream>

using namespace std;

int n, m;
int a[100005], pre[100005];

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        while (m--) {
            int l, r;
            cin >> l >> r;
            cout << pre[r] - pre[l - 1] << endl;
        }
    }

    return 0;
}