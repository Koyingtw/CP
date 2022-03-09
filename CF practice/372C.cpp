// Problem: C. Watching Fireworks is Fun
// Contest: Codeforces - Codeforces Round #219 (Div. 1)
// URL: https://codeforces.com/problemset/problem/372/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
#define MAXN 150001
#define MAXM 301
int n, m, d;
int dp[2][MAXN];

struct Data {
	int a, b, t;
} x[MAXM];

bool cmpt(Data a, Data b) {
	return a.t < b.t;
}

void sol()
{
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++)	{
		cin >> x[i].a >> x[i].b >> x[i].t;
	}
	x[0].t = -INF;
	for (int i = 1; i <= m; i++) {
		deque<pii> dql, dqr;
		for (int j = 1; j <= n; j++) {
			dp[i & 1][j] = -INF;
			while (dql.size() && dql.back().F <= dp[(i - 1) & 1][j])
				dql.pop_back();
			if (dql.size() && dql.front().S < j - d * (x[i].t - x[i - 1].t))
				dql.pop_front();
			dql.push_back({dp[(i - 1) & 1][j], j});
			cmax(dp[i & 1][j], dql.front().F + x[i].b - abs(x[i].a - j));
		}
		for (int j = n; j > 0; j--) {
			while (dqr.size() && dqr.front().F <= dp[(i - 1) & 1][j])
				dqr.pop_front();
			if (dqr.size() && dqr.back().S > j + d * (x[i].t - x[i - 1].t))
				dqr.pop_back();
			dqr.push_front({dp[(i - 1) & 1][j], j});
			cmax(dp[i & 1][j], dqr.back().F + x[i].b - abs(x[i].a - j));
		}
	}
	int ans = -INF;
	for (int i = 1; i <= n; i++)
		cmax(ans, dp[m & 1][i]);
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}