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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 500005
#define MAXM 1000005 
int n, m, s, t;

vector<pii> G[MAXN];
int dis[MAXN];
int from[MAXN];

void dijkstra() {
    MEM(dis, 0x3f);
    dis[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (pq.size()) {
        pii cur = pq.top();
        pq.pop();

        if (dis[cur.S] != cur.F)
            continue;

        for (auto e: G[cur.S]) {
            if (dis[e.F] > dis[cur.S] + e.S) {
                dis[e.F] = dis[cur.S] + e.S;
                pq.push({dis[e.F], e.F});
                from[e.F] = cur.S;
            }
        }
    }
}

void sol() {
    cin >> n >> m >> s >> t;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
    }
    dijkstra();
    
    if (dis[t] > 1e15) {
        cout << -1 << endl;
        return;
    }
    
    int cur = t;
    vector<pii> ans;
    while (cur != s) {
        ans.pb({from[cur], cur});
        cur = from[cur];
    }
    reverse(all(ans));
    cout << dis[t] << " " << ans.size() << endl;
    for (pii it: ans)
        cout << it.F << " " << it.S << endl;
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