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
int c[MAXN], mxchd[MAXN], sub[MAXN], ans[MAXN];
pii mx[MAXN];
vector<int> G[MAXN];
map<int, int> mp[MAXN];

int dfs1(int i, int pa) {
    for (auto &it: G[i]) if (it != pa) {
        int tmp = dfs1(it, i);
        sub[i] += tmp;
        if (tmp > sub[mxchd[i]])
            mxchd[i] = it;
    }
    return sub[i] + 1;
}

map<int, int> &dfs(int i, int pa) {
    // map<int, int> mp;
    if (mxchd[i] > 0) {
        mp[i] = dfs(mxchd[i], i);
        mx[i] = mx[mxchd[i]];
        mp[mxchd[i]].clear();
        // ans[i] = ans[mxchd[i]];
        // cout << i << ' ' << ans[i] << endl;
    }
    for (auto &it: G[i]) if (it != pa && it != mxchd[i]) {
        auto tmp = dfs(it, i);
        for (auto &it2: tmp) {
            mp[i][it2.F] += it2.S;
            if (mp[i][it2.F] > mx[i].S)
                mx[i] = pii(it2.F, mp[i][it2.F]);
        }
        mp[it].clear();
        // ans[i] += ans[it];
        // cout << i << ' ' << ans[it] << endl;
    }

    if (++mp[i][c[i]] > mx[i].S)
        mx[i] = pii(c[i], mp[i][c[i]]);

    for (auto &it: mp[i])
        if (it.S == mx[i].S)
            ans[i] += it.F;
    // ans[i] += mx[i].F;
    // cout << i << ' ' << mx[i].F << endl;
    return mp[i];
}

void sol() {
    cin >> n;
    // MEM(mxchd, -1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs1(1, 1);
    dfs(1, 1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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