// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
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
int dsu[MAXN << 1], cnt[MAXN << 1];
int ans[MAXN];
vector<int> G[MAXN];

void init() {
	for (int i = 0; i < MAXN; i++)
		dsu[i] = i, cnt[i] = i;
}

int find(int i) {
	return (dsu[i] == i ? i : dsu[i] = find(dsu[i]));
}

void unite(int i, int j) {
	i = find(i);
	j = find(j);
	if (cnt[i] < cnt[j])
		swap(i, j);
	dsu[j] = i;
	cnt[i] += cnt[j];
}

void dfs(int i, int dep) {
	ans[i] = dep;
	for (int e: G[i]) {
		if (!ans[e])
			dfs(e, dep % 2 + 1);
	}
}

void sol() {
	cin >> n >> m;
	init();
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		unite(a * 2, b * 2 + 1);
		unite(a * 2 + 1, b * 2);
	}
	for (int i = 1; i <= n; i++) {
		if (find(i * 2) == find(i * 2 + 1))	{
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}	
	for (int i = 1; i <= n; i++) {
		if (!ans[i])
			dfs(i, 1);
		cout << ans[i] << " ";
	}
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