#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define endl '\n'
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 2005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
vector<pii> g[MAXN];
vector<pii> E;
bitset<MAXN * MAXN> used;
bool ans[MAXN][MAXN];

struct Tarjan_AP {
    int low[MAXN], dep[MAXN], timestamp = 0;
    bitset<MAXN> isAP;
    vector<int> AP;

    void dfs(int i, int fa, int rm) {
        dep[i] = low[i] = ++timestamp;
        int chdcnt = 0;

        for (int e: G[i]) {
            if (e == rm)
                continue;

            if (!dep[e] || dep[e] > timestamp) {
                dfs(e, i, rm);
                chdcnt++;
                cmin(low[i], low[e]);
                if (low[e] >= dep[i])
                    isAP[i] = true;
            }
            cmin(low[i], dep[e]);
        }

        if (i == fa && chdcnt < 2)
            isAP[i] = false;
        if (isAP[i])
            AP.pb(i);
    }

    void main(int rm) {
        timestamp = 0;
        MEM(dep, 0);
        isAP.reset();
        AP.clear();

        dfs(rm % n + 1, rm % n + 1, rm);
    }
} AP;


void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
        E.pb({a, b});
    }


    for (int i = 0; i < 3; i++) {
        bitset<MAXN> vis;
        for (int j = 1; j <= n; j++) {
            if (vis[j])
                continue;
            queue<int> q;
            q.push(j);
            vis[j] = true;

            while(q.size()) {
                auto now = q.front();
                q.pop();
                for (auto e: g[now]) {
                    if (used[e.S] || vis[e.F])
                        continue;
                    q.push(e.F);
                    vis[e.F] = true;
                    used[e.S] = true;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!used[i])
            continue;
        G[E[i].F].pb(E[i].S);
        G[E[i].S].pb(E[i].F);
    }

    int cnt = 0;

    AP.main(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (AP.isAP[j] && AP.isAP[i]) {
                cnt += !ans[j][i];
                ans[j][i] = true;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        AP.main(i);
        for (int it: AP.AP) {
            cnt += !ans[min(it, i)][max(it, i)];
            ans[min(it, i)][max(it, i)] = true;
        }
    }

    cout << cnt << endl;
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