// Problem: Shortest Routes I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1671/
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
int dis[MAXN];
vector<pair<int, int>> G[MAXN];

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	dis[s] = 0;
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S] != now.F)
			continue;
			
		for (auto e: G[now.S]) {
			if (dis[e.F] > now.F + e.S) {
				dis[e.F] = now.F + e.S;
				pq.push({dis[e.F], e.F});
			}
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	
	dijkstra(1);
	
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
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