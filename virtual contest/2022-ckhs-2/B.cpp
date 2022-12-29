#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#define F first
#define S second
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
using namespace std;

#define MAXN 200005
#define MAXM 1000005

int n, m;
int dis[MAXN * 2];
vector<pii> G[MAXN * 2];

struct Group {
    int k, w;
    vector<int> G;
} x[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i].k >> x[i].w;
        for (int j = 0, a; j < x[i].k; j++) {
            cin >> a;
            G[a].pb({n + i, x[i].w});
            G[n + i].pb({a, x[i].w});
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    MEM(dis, 0x3f);
    dis[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();

        if (dis[now.S] != now.F)
            continue;

        for (auto e: G[now.S]) {
            if (dis[e.F] > dis[now.S] + e.S) {
                dis[e.F] = dis[now.S] + e.S;
                pq.push({dis[e.F], e.F});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cmax(ans, dis[i]);
    }

    cout << (ans < INF ? ans / 2 : -1) << endl;
}

signed main() {
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}