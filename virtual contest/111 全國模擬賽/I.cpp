#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 998244353;

using namespace std;

#define MAXN 200005
int n, m;
int x[MAXN];
int pre[MAXN];
int dp[2][MAXN];
int sum[MAXN];

int fac(int a) {
    int res = 1;
    for (int i = 1; i <= a; i++)
        res *= i;
    return res;
}

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;
            res %= P;
        }
        a *= a;
        a %= P;
        b /= 2;
    }
    return res;
}

void brute() {
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int tmp = 1;
        for (int i = 0; i < n; i++) if (mask & (1 << i)) {
            tmp *= x[i + 1];
            tmp %= P;
        }
        tmp *= __builtin_popcount(mask);
        ans += tmp;
        ans %= P;
    }
    cout << ans << endl;
}

void sol() {
    cin >> n;
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        dp[1][i] = x[i];
        ans += x[i];
        sum[1] += x[i];
    }
    brute();

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i % 2][j] = x[j] * (sum[i - 1] - dp[(i - 1) % 2][j]);
            dp[i % 2][j] %= P;
            sum[i] += dp[i % 2][j];
            cout << dp[i % 2][j] << ' ';
        }
        cout << endl;
        sum[i] %= P;
        if (i > 2)
            sum[i] -= 5 * sum[i - 1];
        // sum[i] /= 2;
        cout << sum[i] << endl;
        ans += sum[i];
    }

    cout << ans << endl;
}

/*
4
1 2 3 4
*/

signed main() {
    Koying;
    sol();
    return 0;
}