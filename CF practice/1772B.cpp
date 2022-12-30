#include <bits/stdc++.h>

using namespace std;

const int x[] = {0, 0, 1, 1};
const int y[] = {0, 1, 1, 0};

int a[2][2];

signed main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> a[i][j];
        for (int k = 0; k < 4; k++) {
            int b = a[x[k]][y[k]];
            int c = a[x[(k + 1) % 4]][y[(k + 1) % 4]];
            int d = a[x[(k + 2) % 4]][y[(k + 2) % 4]];
            int e = a[x[(k + 3) % 4]][y[(k + 3) % 4]];
            if (c > b && d > c && e < d && b < e) {
                cout << "YES" << endl;
                break;
            }
            if (k == 3) {
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}