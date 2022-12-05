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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m, k;
multiset<int> dis[MAXN];
pii from[MAXN];
vector<array<int, 3>> Edge;
vector<pii> G[MAXN], G2[MAXN];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dis[1].insert(0);
    while (SZ(pq)) {
        auto now = pq.top();
        pq.pop();

        if (SZ(dis[now.S]) && now.F > *dis[now.S].rbegin())
            continue;

        // while (SZ(dis[now.S]) > k)
        //     dis[now.S].erase(--dis[now.S].end());

        for (auto e: G[now.S]) {
            
            if (SZ(dis[e.F]) < k || *dis[e.F].rbegin() > now.F + e.S) {
                if (SZ(dis[e.F]) == k)
                    dis[e.F].erase(--dis[e.F].end());
                dis[e.F].insert(now.F + e.S);
                pq.push({now.F + e.S, e.F});
            }

        }
    }
}


void sol() {
    cin >> n >> m >> k;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        Edge.pb({a, b, c});
    }

    dijkstra();

    // for (int i = 1; i <= n; i++) {

    // }
    for (int it: dis[n]) {
        cout << it << ' ';
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