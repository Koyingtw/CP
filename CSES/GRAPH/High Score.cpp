// Problem: High Score
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1673
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 2505
#define MAXM 5005
int n, m;
int dis[MAXN];
bool has_neg_cir[MAXN];
bitset<MAXN> vis;
vector<pair<int, int>> G[MAXN];
pair<pair<int, int>, int> E[MAXM];

bool find_neg_cir(int i, int sum, int start) {
	if (vis[i])
		return (i == start && sum < 0);
	vis[i] = true;
	
	bool res = false;
	for (pii e: G[i]) {
		res |= find_neg_cir(e.F, sum + e.S, start);
	}
	return res;
}

void dfs(int i) {
	vis[i] = true;
	
	for (pii e: G[i]) {
		if (!vis[e.F])
			dfs(e.F);
	}
}

bool check(int i, int j) {
	vis.reset();
	dfs(i);
	
	return vis[j];
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b, v; i < m; i++) {
		cin >> a >> b >> v;
		G[a].pb({b, -v});
		E[i] = {{a, b}, -v};
	}
	
	for (int i = 1; i <= n; i++)
		sort(G[i].begin(), G[i].end(), [](pair<int, int> _a, pair<int, int> _b) {
			return _a.S < _b.S;
		});
	
	MEM(dis, 0x3f);
	dis[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		vis.reset();
		has_neg_cir[i] = find_neg_cir(i, 0, i);
		
		if (has_neg_cir[i]) {
			if (check(1, i) && check(i, n)) {
				cout << -1 << endl;
				return;
			}
		}
	}
	
	
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++)	{
			int a = E[j].F.F;
			int b = E[j].F.S;
			int v = E[j].S;
			if (dis[b] > dis[a] + v) {
				dis[b] = dis[a] + v;
			}
		}
	}
	cout << -dis[n] << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}