#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

ll P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

const int MAXN = 505;
const int MAXM = 1000005;

int n, m;
int dp[MAXN][MAXN];

int fpow(int a, int b) {
    if (b < 0)
        return 0;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void sol() {
    cin >> n >> m >> P;
    int mask = (n + 1) * n / 2;
    // cout << mask << endl;

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += fpow(2, j - i + 1);
            ans %= P;
        }
    }
    if (m == 1) {
        cout << ans << endl;
    }
    else if (m == 2) {
        cout << ans * ans % P << endl;
    }
    else {
        cout << ans * ans - fpow(3, mask) % P << endl;
    }
    return;
    // if (m <= 3) {
    // }
    // for (int i = 0; i <= mask; i++)
    //     dp[i][0] = 1;
    // for (int i = 1; i <= mask; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         for (int k = 0; k <= i; k++)
    //             dp[i][j] += dp[k][j - 1];
    //     }
    //     cout << dp[mask][m] << endl;
    // }
    // cout << dp[mask][m] << endl;
}

signed main() {
    Koying;
    int t = 1;
    // cin >> t;
    while (t--)
        sol();
}