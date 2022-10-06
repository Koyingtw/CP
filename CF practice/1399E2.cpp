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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int sum = 0, ans = 0;
vector<tuple<int, int, int>> G[MAXN];
bitset<MAXN> vis;
vector<int> E[2];


void init() {
    for (int i = 1; i <= n; i++)
        G[i].clear();
    E[0].clear();
    E[1].clear();
    E[1].pb(0);
    sum = 0, ans = 0;
}

int dfs(int i) {
    vis[i] = 1;

    int res = 0;
    for (auto [a, b, c]: G[i]) {
        if (!vis[a]) {
            int tmp = dfs(a);
            sum += b * tmp;
            res += tmp;
            
            int cost = b;

            for (int j = 1; j <= 25; j++) {
                cost /= 2;
                if (b * tmp - cost * tmp)
                    E[c % 2].pb(b * tmp - cost * tmp);
                b /= 2;
            }
        }
    }
    return res + (res == 0);
}


void sol() {
    cin >> n >> m;
    init();

    for (int i = 1, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        G[a].pb({b, c, d});
        G[b].pb({a, c, d});
    }

    vis.reset();
    dfs(1);
    sort(all(E[0]), greater<int>());
    sort(E[1].begin() + 1, E[1].end(), greater<int>());

    for (int i = 1; i < E[1].size(); i++)
        E[1][i] += E[1][i - 1];

    int ans = INF;

    if (E[1].size() && sum - E[1].back() <= m)
        ans = lower_bound(all(E[1]), sum - m) - E[1].begin();
    for (int i = 0; i < E[0].size(); i++) {
        sum -= E[0][i];
        if (sum <= m) {
            cmin(ans, (i + 1) * 2);
        }
        if (E[1].size() && sum - E[1].back() <= m)
            cmin(ans, lower_bound(all(E[1]), sum - m) - E[1].begin() + 2 * (i + 1));
    }

    cout << ans << endl;
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