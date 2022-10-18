#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int P = 1e9 + 7;

#define MAXN 3005
#define MAXM 105

int n, m;
int dp[MAXM][MAXN];

void sol() {
    cin >> n >> m;
    cmin(m, n);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                dp[j + 1][(k + i) % n] += dp[j][k];
                dp[j + 1][(k + i) % n] %= P;
            }
        }
    }

    cout << dp[m][0] << endl;
}

signed main() {
    IOS;
    int _ = 1;
    cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}