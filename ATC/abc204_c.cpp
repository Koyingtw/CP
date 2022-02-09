// Problem: C - Tour
// Contest: AtCoder - AtCoder Beginner Contest 204
// URL: https://atcoder.jp/contests/abc204/tasks/abc204_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma optimize("O3")
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
/******************************************************************************/
#define MAXN 2005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
bitset<MAXN> can[MAXN], vis;

void dfs(int st, int i)
{
	vis[i] = 1;
	can[st][i] = true;
	for(int e: G[i])	
		if(!vis[e])
			dfs(st, e);
	return;
}

void sol()
{
	cin >> n >> m;
	for(int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		G[u].pb(v);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		vis.reset();
		dfs(i, i);
		for(int j = 1; j <= n; j++)
			ans += can[i][j];
	}
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