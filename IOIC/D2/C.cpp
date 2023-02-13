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

const int P = 998244353;

#define MAXN 55

int n, m, q;
string s;

int dp[MAXN][10];

void pre() {
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j < n; j++)
            dp[i][0] += dp[i - 1][j] * 9;
        dp[i][n] += dp[i - 1][n] * 10;

        cout << dp[i][0] << ' ';
        for (int j = 1; j <= n; j++) {
            dp[i][0] %= P;
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] %= P;
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int fpow(int a, int b) {
    if (b <= 0)
        return 0;
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= P;
        }
        a *= a;
        a %= P;
        b >>= 1;
    }
    return res;
}

void sol() {
    cin >> n >> s >> q;
    pre();


    while (q--) {
        cin >> m;
        int ten = fpow(10, m);
        if (m < 55) {
            int sum = 0, ans = 0;
            for (int i = 0; i <= n; i++) {
                sum += dp[m][i];
            }
            for (int i = 0; i <= m; i++) {
                ans += dp[i][n];
                ans %= P;
            }
            // ans = dp[m][n];
            cout << sum << ' ' << ans << endl;
            cout << fpow(10, m - n) * (m - n + 1) << ' ' << dp[m][n] << ' ' << (ans * fpow(ten, P - 2) % P) % P << endl;
        }
        cout << (fpow(10, m - n) * (m - n + 1) % P * fpow(ten, P - 2)) % P << endl;
    }
}

signed main() {
    Koying;
    sol();
}