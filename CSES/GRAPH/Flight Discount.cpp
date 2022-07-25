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
int dis[MAXN][2];
vector<pair<int, int>> G[MAXN];


void dijkstra(int s) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	MEM(dis, 0x3f);
	dis[1][0] = dis[1][1] = 0;
	pq.push({0, {1, 0}});
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S.F][now.S.S] != now.F)
			continue;
		
		for (auto e: G[now.S.F]) {
			if (dis[e.F][now.S.S] > now.F + e.S) {
				dis[e.F][now.S.S] = now.F + e.S;
				pq.push({dis[e.F][now.S.S], {e.F, now.S.S}});
			}
			if (now.S.S == 0 && dis[e.F][now.S.S + 1] > now.F + e.S / 2) {
				dis[e.F][now.S.S + 1] = now.F + e.S / 2;
				pq.push({dis[e.F][now.S.S + 1], {e.F, now.S.S + 1}});
			}
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	dijkstra(1);
	cout << dis[n][1] << endl;
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