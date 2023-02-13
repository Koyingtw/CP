#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int MAXM = 3005;

int n, m;
int a[MAXN], b[MAXM];

void sol() {
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        for (int j = 1; j < i; j++) if (i % j == 0) {
            b[i] -= b[j];
        }
        if (b[i] < 0) {
            cout << -1 << endl;
            return;
        }
        for (int j = 0; j < b[i]; j++)
            v.push_back(i);
    }

    if (v.size() != n) {
        cout << -1 << endl;
        return;
    }
        



    for (auto it: v)
        cout << it << ' ';
    cout << endl;
}

signed main() {
    sol();
}