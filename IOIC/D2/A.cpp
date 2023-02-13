#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif 
using namespace std;

#define MAXN 5005

int n;
int x[MAXN];
set<int> st;

void sol() {
    cin >> n;

    if (n > 30) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; i++) {
        x[i] = ((1 << 30) - 1) ^ (1 << i);
    }
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << endl;
}

signed main() {
    Koying;
    sol();
}