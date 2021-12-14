// Problem: A. Parsa's Humongous Tree
// Contest: Codeforces - Codeforces Round #722 (Div. 1)
// URL: https://codeforces.com/contest/1528/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
pii dp[MAXN];
pii x[MAXN];
vi G[MAXN];
bitset<MAXN> vis;

void dfs(int i)
{
	vis[i] = true;
	int l = 0, r = 0;
	for(int e: G[i])
	{
		if(!vis[e])
		{
			dfs(e);
			l += max(dp[e].F + abs(x[i].F - x[e].F), dp[e].S + abs(x[i].F - x[e].S));
			r += max(dp[e].F + abs(x[i].S - x[e].F), dp[e].S + abs(x[i].S - x[e].S));
		}
	}
	dp[i] = {l, r};
}

void init()
{
	for(int i = 0; i < MAXN; i++)
	{
		G[i].clear();
	}
	vis.reset();
	MEM(dp, 0);
}

void sol()
{
	cin >> n;	
	init();
	for(int i = 1; i <= n; i++)
		cin >> x[i].F >> x[i].S;
	for(int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1);
	cout << max(dp[1].F, dp[1].S) << endl;

}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}