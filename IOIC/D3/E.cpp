#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define pb push_back
#define lowbit(x) (x & (-x))
using namespace std;

#define MAXN 2005
#define MAXM 1000005

#if !LOCAL
#define endl '\n'
#pragma GCC optimize ("Ofast, unroll-all-looops")
#endif

int n, m;

// struct Fenwick_Tree {
//     int arr[MAXN << 1];

//     void update(int i, int val) {
//         for (; i < MAXN * 2; i += lowbit(i))
//             arr[i] += val;
//     }

//     int query(int i) {
//         int res = 0;
//         for (; i > 0; i -= lowbit(i))
//             res += arr[i];
//         return res;
//     }
// } BIT;

int x[MAXN], pre[MAXN];
int dp[MAXN][MAXN];


void sol() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '(')
            x[i] = 1;
        else
            x[i] = -1;
        pre[i] = pre[i - 1] + x[i];
        // BIT.update(i, pre[i]);
    }

    int ans = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n)
                break;
            // cout << i << ' ' << j << endl;
            if (x[i] == 1 && x[j] == -1)
                cmax(dp[i][j], dp[i + 1][j - 1] + 2);
            if (x[i] == 1 && x[i + 1] == -1)
                cmax(dp[i][j], dp[i + 2][j] + 2);
            if (x[j - 1] == 1 && x[j] == -1)
                cmax(dp[i][j], dp[i][j - 2] + 2);
            cmax(dp[i][j], dp[i + 1][j]);
            cmax(dp[i][j], dp[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            ans += dp[i][j];
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    cout << ans << endl;
}

signed main() {
    Koying;
    sol();
}