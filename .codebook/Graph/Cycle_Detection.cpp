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
int n, m;
vector<vector<pii>> G(MAXN);
int vis[MAXN];
stack<pii> p;
vector<int> ans;

bool dfs(int i, int fa) {
    vis[i] = 2;

    bool res = 0;

    for (pii e: G[i]) {
        if (e.F == fa)
            continue;
        if (vis[e.F] == 2 && !ans.size()) {
            auto tmp = p;
            ans.pb(e.S);
            while (tmp.size()) {
                ans.pb(tmp.top().S);
                if (tmp.top().F == e.F)
                    break;
                tmp.pop();
            }
            return 1;
        }
        if (!vis[e.F]) {
            p.push({i, e.S});
            res |= dfs(e.F, i);
            if (!res && p.size())
                p.pop();
        }
    }
    vis[i] = 1;
    return res;
}

void sol() {
	cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        a++, b++;
        G[a].pb({b, i});
    }
    for (int i = 1; i <= n && ans.empty(); i++) {
        dfs(i, i);
    }

    if (ans.size()) {
        cout << ans.size() << endl;
        reverse(all(ans));
        for (int it: ans)
            cout << it - 1 << endl;
    }
    else   
        cout << -1 << endl;
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