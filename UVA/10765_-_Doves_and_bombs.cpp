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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];

struct Tarjan_AP {
    int low[MAXN], dep[MAXN];
    pii AP[MAXN];
    int timestamp = 0;
    bitset<MAXN> vis;

    void dfs(int i, int fa) {
        // cout << i << endl;
        low[i] = dep[i] = ++timestamp;
        int cnt = 0;
        for (int e: G[i]) {
            if (e == fa)
                continue;

            if (!dep[e]) {
                dfs(e, i);
                cnt++;
                cmin(low[i], low[e]);
                if (low[e] >= dep[i] && (i != fa || cnt > 1)) {
                    // if (!AP[i].F)
                    //     AP[i].F = 1;
                    AP[i].F++;
                    // cout << i << endl;
                }
            }
            cmin(low[i], dep[e]);

        }
    }

    void main() {
        for (int i = 0; i < n; i++) {
            low[i] = dep[i] = vis[i] = timestamp = 0;
            AP[i] = {0, -i};
        }
        for (int i = 0; i < n; i++)
            if (!dep[i])
                dfs(i, i);
        sort(AP, AP + n, greater<pii>());
    }
} AP;

void sol() {
    while (cin >> n >> m && n + m) {
        for (int i = 0; i < n; i++)
            G[i].clear();
        int a, b;
        while (cin >> a >> b && a >= 0) {
            G[a].pb(b);
            G[b].pb(a);
        }
        AP.main();
        for (int i = 0; i < m; i++) {
            cout << -AP.AP[i].S << ' ' << AP.AP[i].F + 1 << endl;
        }
        cout << endl;
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