#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;

#define MAXN 200005
int n, m, s, t, d;
int p[MAXN];
pii from[MAXN];
int dis[MAXN];
int mncnt = 0;
vector<pii> G[MAXN];

int dijkstra() {
    int mxedge = 0;
    mncnt = 0;

    MEM(dis, 0x3f);
    MEM(from, 0);

    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();

        if (dis[now.S] != now.F)
            continue;

        for (auto e: G[now.S]) {
            if (dis[e.F] > now.F + p[e.S]) {
                dis[e.F] = now.F + p[e.S];
                pq.push({dis[e.F], e.F});
                from[e.F] = {now.S, e.S};

                if (e.F == t && dis[e.F] <= d)
                    mncnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) if (i != s && p[from[i].S] > p[mxedge])
        mxedge = from[i].S;
    return mxedge;
}

void sol() {
    cin >> n >> m >> s >> t >> d;
    for (int i = 1, a; i <= m; i++) {
        cin >> a;
        p[a] = i;
    }
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        G[a].pb({b, i});
        G[b].pb({a, i});
    }

    dijkstra();

    if (dis[t] > d) {
        cout << "NO" << endl;
        return;
    }

    do {
        int mxedge = dijkstra();

        for (int i = 1; i <= m; i++) if (p[i] > p[mxedge])
            p[i] += d;
        p[mxedge] += d - dis[t];
    } while (dis[t] < d);


    cout << "YES" << endl;


    for (int i = 1; i <= m; i++)
        cout << p[i] << " \n"[i == m];
    // cout << endl;
}

/*
4 5 1 4 10
5 1 4 3 2
1 3
1 2
3 4
2 3
2 4


5 4 3 4 1
1 2 3 4
3 1
1 2
2 5
5 4
*/

signed main() {
    Koying;
    sol();
    return 0;
}