// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int leaf = 1;
pii mx = {0, 0};
vector<int> G[MAXN];
bitset<MAXN> vis;

void dfs(int i, int pre, int dep) {
	if (dep > mx.F) {
		mx = {dep, i}; 	
	}
	vis[i] = true;
	for (int e: G[i]) {
		if (vis[e])
			continue;
		dfs(e, i, dep + 1);
	}
}

void sol()
{
	cin >> n;
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, 0, 1);
	vis.reset();
	dfs(mx.S, 0, 1);
	
	cout << mx.F - 1 << endl;
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