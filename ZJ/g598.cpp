#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005
int n, m, p, k;
int color[MAXN];
vector<pair<int, int>> G[MAXN];
bitset<MAXN> vis, illegal;

bool dfs(int i, int mid)
{
    vis[i] = true;

    bool legal = true;
    for (auto e : G[i]) {
        if (e.second > mid || illegal[e.second]) continue;
        if (vis[e.first] && color[e.first] == color[i]) {
            return false;
        }

        if (!vis[e.first]) {
            color[e.first] = 1 + (color[i] == 1);
            legal &= dfs(e.first, mid);
        }
    }
    return legal;
}

bool check(int mid)
{
    vis.reset();
    memset(color, 0, sizeof(color));

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            color[i] = 1;
            if (!dfs(i, mid)) return false;
        }
    }
    return true;
}

void sol()
{
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back({b, 0});
        G[b].push_back({a, 0});
    }

    cin >> p >> k;
    for (int i = 1; i <= p; i++) {
        for (int j = 0, a, b; j < k; j++) {
            cin >> a >> b;
            G[a].push_back({b, i});
            G[b].push_back({a, i});
        }
    }

    vector<int> ans;
    for (int i = 0; i < 3 && !check(p); i++) {
        int l = 0, r = p;
        while (l < r) {
            int mid = (l + r) / 2;

            if (check(mid))
                l = mid + 1;
            else
                r = mid;
        }

        if (r > 0) {
            illegal[r] = true;
            ans.push_back(r);
        }
    }

    for (int it : ans) cout << it << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    // while (cin >> t)
    {
        while (t--) {
            sol();
        }
    }

    return 0;
}