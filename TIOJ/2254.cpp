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
vector<pii> G[MAXN];
vector<pii> E;
int vis[MAXN];
int tt = 0;
int in[MAXN];

bool dfs(int i, int mid) {
    vis[i] = 2;
    bool legal = true;
    for (auto e: G[i]) if (e.S > mid) {
        if (!vis[e.F])
            legal &= dfs(e.F, mid);
        else if (vis[e.F] == 2)  
            return false;
    }
    vis[i] = 1;
    in[i] = ++tt;
    return legal;
}

bool check(int mid) {
    bool legal = true;
    MEM(vis, 0);
    MEM(in, 0);
    tt = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        legal &= dfs(i, mid);
    }
    return legal;
}

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        E.pb({a, b});
    }

    int l = 0, r = INF;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    check(r);

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        auto [a, b] = E[i];
        if (in[a] < in[b]) {
            ans.pb(i + 1);
        }
    }

    cout << r << ' ' << ans.size() << endl;
    for (int it: ans)
        cout << it << endl;
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