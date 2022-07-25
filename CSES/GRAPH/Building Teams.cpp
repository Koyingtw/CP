// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int color[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

bool dfs(int i) {
	vis[i] = true;
	
	bool legal = true;
	for (int e: G[i]) {
		if (color[e] == color[i])
			return false;
			
		if (!vis[e]) {
			color[e] = 1 + (1 == color[i]);
			legal &= dfs(e);
		}
	}
	return legal;
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	bool legal = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			color[i] = 1;
			legal &= dfs(i);
		}
		if (!legal) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << color[i] << " ";
	cout << endl;
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