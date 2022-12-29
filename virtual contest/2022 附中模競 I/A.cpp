#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
#define MEM(x, n) memset(x, n, sizeof(x))
#define F first
#define S second
#define all(v) v.begin(), v.end()
#if !LOCAL
#define endl '\n'
#pragma optimize("Ofast, unroll-all-loops")
#endif

using namespace std;

#define MAXN 1000005
#define MAXM 1000005

int n, m;
int x[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    reverse(x, x + n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (x[i] > x[i - 1]) {
            int tmp = (x[i] + x[i - 1] - 1) / x[i - 1];
            ans += tmp - 1;
            x[i] /= tmp;
        }
        // cout << x[i] << ' ';
    }
    cout << ans << endl;
}

signed main() {
    Koying
    int _ = 1;
    // cin >> _
    while (_--) {
        sol();
    }

    return 0;
}