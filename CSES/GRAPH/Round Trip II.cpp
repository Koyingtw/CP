// Problem: Round Trip
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1669
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
int vis[MAXN];
vector<int> G[MAXN], ans;
stack<int> path;

void dfs(int i, int pre) {
	vis[i] = 2;
	path.push(i);
	
	for (int e: G[i]) {
		if (!vis[e])
			dfs(e, i);
			
		if (vis[e] == 2 && ans.empty()) {
			ans.push_back(e);
			while (path.size()) {
				ans.push_back(path.top());
				if (path.top() == e)
					break;
				path.pop();
			}
			reverse(ans.begin(), ans.end());
			return;
		}
	}
	
	vis[i] = 1;
	
	if (path.size())
		path.pop();
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, i);
	
	if (ans.size()) {
		cout << ans.size() << endl;
		for (int it: ans)
			cout << it << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
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