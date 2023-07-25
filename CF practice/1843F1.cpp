#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<array<int, 3>> add;
vector<array<int, 4>> qq;
vector<int> G[MAXN];
int mx[MAXN], mn[MAXN], sum[MAXN], mxsum[MAXN], mnsum[MAXN];

struct Fenwick_Tree {
    int mx[MAXN], mn[MAXN];
    void init() {
        for (int i = 0; i <= n; i++)
            mx[i] = -INF, mn[i] = INF;
    }
    void update(int x, int v) {
        for (; x <= n; x += lowbit(x)) {
            cmax(mx[x], v);
            cmin(mn[x], v);
        }
    }

    pii query(int x) {
        pii res = {-INF, INF};
        for (; x; x -= lowbit(x)) {
            cmax(res.F, mx[x]);
            cmin(res.S, mn[x]);
        }
        return res;
    }
} BIT;

void sol() {
    cin >> n;
    add.clear();
    qq.clear();

    for (int i = 1; i <= n; i++)
        G[i].clear();

    sum[1] = mx[1] = 1;
    mn[1] = 0;
    mxsum[1] = 1;
    mnsum[1] = 0;
    int node = 1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int v, x;
            cin >> v >> x;
            add.pb({v, x, i});
            G[v].pb(++node);
            sum[node] = sum[v] + x;
            mn[node] = min(mn[v], sum[node]);
            mx[node] = max(mx[v], sum[node]);
            mxsum[node] = mx[node];
            mxsum[node] = max(mxsum[v], sum[node] - mn[node]);
            mnsum[node] = mn[node];
            mnsum[node] = min(mnsum[v], sum[node] - mx[node]);
        }
        else {
            int u, v, k;
            cin >> u >> v >> k;
            // cout << mnsum[v] << " " << mxsum[v] << endl;
            if (mnsum[v] <= k && k <= mxsum[v])
                cout << "YES" << endl;
            else {
                cout << "NO" << endl;
            }
        }
    }
    // for (int i = 1; i <= node; i++)
    //     cout << mnsum[i] << " " << mxsum[i] << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}