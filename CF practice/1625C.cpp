// Problem: C. Road Optimization
// Contest: Codeforces - Codeforces Round #765 (Div. 2)
// URL: https://codeforces.com/contest/1625/problem/C
// Memory Limit: 128 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 505
#define MAXM 1000005 
int n, m, k;
int dp[MAXN][MAXN];
int x[MAXN], y[MAXN];
void sol()
{
	MEM(dp, 63);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	x[n] = m;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		cin >> y[i];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + (x[i] - x[i - 1]) * (y[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = i - 1; l >= 0; l--) {
				if (j - (i - l - 1) < 0) break;
				cmin(dp[i][j], dp[l][j - (i - l - 1)] + (x[i] - x[l]) * (y[l]));
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= k; i++)
		cmin(ans, dp[n][i]);
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    // while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}