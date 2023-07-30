#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
map<int, int> mp = {
    {0, 1}, {1, 10}, {2, 100}, {3, 1000}, {4, 10000}
};
int dp[MAXN][2][5]; // dp[i][j][k] -> i: 第幾項，j: 是否有更改，k: 前綴最大值

void sol() {
    string s;
    cin >> s;
    n = s.size();

    reverse(all(s));

    for (int i = 1; i <= n; i++) {
        x[i] = s[i - 1] - 'A';
        for (int j = 0; j < 5; j++) {
            dp[i][0][j] = dp[i][1][j] = -INF;
        }
    }

    MEM(dp[0], 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (j == x[i]) {
                    if (max(k, j) > j) {
                        cmax(dp[i][0][max(k, j)], dp[i - 1][0][k] - mp[j]);
                        cmax(dp[i][1][max(k, j)], dp[i - 1][1][k] - mp[j]);
                    }
                    else {
                        cmax(dp[i][0][max(k, j)], dp[i - 1][0][k] + mp[j]);
                        cmax(dp[i][1][max(k, j)], dp[i - 1][1][k] + mp[j]);
                    }
                }
                else {
                    if (max(k, j) > j) {
                        cmax(dp[i][1][max(k, j)], dp[i - 1][0][k] - mp[j]);
                    }
                    else
                        cmax(dp[i][1][max(k, j)], dp[i - 1][0][k] + mp[j]);
                }
            }
        }
    }

    int ans = -INF;

    for (int j = 0; j < 5; j++) {
        cmax(ans, dp[n][0][j]);
        cmax(ans, dp[n][1][j]);
    }


    cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}