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
#define ls (i << 1)
#define rs (i << 1 | 1)
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
vector<vector<int>> G(200005, vector<int>());

struct LCA {
    int p[MAXN], d[MAXN], dp[30][MAXN];

    void build_p(vector<vector<int>> &G, int i, int fa) {
        p[i] = fa;
        for (auto e: G[i]) if (!p[e]) {
            d[e] = d[i] + 1;
            build_p(G, e, i);
        }
    }

    void init(vector<vector<int>> &G) {
        MEM(p, 0);
        for (int i = 1; i <= n; i++) if (!p[i]) {
            d[i] = 1;
            build_p(G, i, i);
        }

        for (int i = 1; i <= n; i++)
            dp[0][i] = p[i];
        for (int i = 1; i < 30; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }

    int jump(int i, int d) {
        for (int j = 20; ~j; j--) {
            if (d - (1 << j) >= 0) {
                d -= (1 << j);
                i = dp[j][i];
            }
        }
        return i;
    }

    int findLCA(int i, int j) {
        if (d[i] > d[j])
            i = jump(i, d[i] - d[j]);
        if (d[j] > d[i])
            j = jump(j, d[j] - d[i]);
        
        if (i == j)
            return i;
        
        for (int k = 20; ~k; k--) {
            if (dp[k][i] != dp[k][j])
                i = dp[k][i], j = dp[k][j];
        }
        return dp[0][i];
    }
} LCA;

int lcacnt[MAXN], ans[MAXN];

vector<int> Start[MAXN], End[MAXN];

int dfs(int i, int fa) {
    for (int e: G[i]) if (e != fa) {
        ans[i] += dfs(e, i);
    }
    ans[i] += End[i].size();
    return ans[i] - Start[i].size();
}

void sol() {
    cin >> n >> m;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    LCA.init(G);

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        int lca = LCA.findLCA(a, b);
        pii p1(lca, a), p2(lca, b);
        lcacnt[lca]++;
        
        Start[lca].pb(a);
        End[a].pb(lca);
        Start[lca].pb(b);
        End[b].pb(lca);
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] - lcacnt[i] << " \n"[i == n];
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