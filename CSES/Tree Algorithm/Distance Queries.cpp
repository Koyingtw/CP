// Problem: Distance Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1135
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
int dep[MAXN], inTime[MAXN], outTime[MAXN], tt = 0;
vector<int> G[MAXN], GG[MAXN];
bitset<MAXN> vis;

void dfs(int i, int depth) {
	vis[i] = true;
	
	inTime[i] = tt++;
	dep[i] = depth;
	
	for (int e: G[i]) 
		if (!vis[e])
			dfs(e, depth + 1);
	outTime[i] = tt++;
}

struct Sparse_table {
	int arr[20][MAXN];
	
	
	void build() {
		dfs(1, 1);
		arr[0][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int e: G[i])
				if (dep[e] > dep[i])
					arr[0][e] = i;
		}
		
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = arr[i - 1][arr[i - 1][j]];
			}
		}
	}
	
	bool isac(int a, int b) {
		return (inTime[a] <= inTime[b] && outTime[a] >= outTime[b]);
	}
	
	int query(int a, int b) {
		int dis = 0;
		
		if (dep[a] < dep[b])
			swap(a, b);
		
		for (int i = 19; i >= 0; i--) {
			if (!isac(arr[i][a], b))
				a = arr[i][a];
		}
		
		return (a == b ? a : arr[0][a]);
	}
} ST;

void sol() {
	cin >> n >> m;
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	
	ST.build();
	
	int a, b;
	while (m--) {
		cin >> a >> b;
		int lca = ST.query(a, b);
		cout << dep[a] - dep[lca] + dep[b] - dep[lca] << endl;
	}
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