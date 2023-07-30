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
vector<pii> G[MAXN];


void dfs(int i, int fa, int mn = INF, int mx = -INF) {
    pii ans(0, 0);
    for (auto it: G[i]) if (it.F != fa) {
        dfs(it.F, i, min(mn, it.S), max(mx, it.S));
        if (mn <= it.S && it.S <= mx) {
            if (!ans.F)
                ans.F = it.F;
            else {
                ans.S = it.F;
                cout << 1 << ' ' << ans.F << ' ' << 1 << ' ' << ans.S << endl;
                exit(0);
            }
        }
    }
}

void sol() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    dfs(1, 1);
    cout << -1 << endl;
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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