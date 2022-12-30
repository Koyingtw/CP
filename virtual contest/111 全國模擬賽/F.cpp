#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;

#define MAXN 200005
int n, m;
int dep[MAXN], pa[MAXN], depcnt[MAXN];
vector<int> G[MAXN];
set<int> d[MAXN];

int dfs(int i) {
    int res = 0;
    int cnt = 0;
    for (int e: G[i]) if (e != pa[i]) {
        pa[e] = i;

        dep[e] = dep[i] + 1;
        d[dep[e]].insert(i);
        depcnt[dep[e]]++;

        cnt++;
        int tmp = dfs(e);
        res += tmp;
    }

    if (cnt == 0)
        return 0;
    if (i == m && res == 0)
        res = 1;

    return res + cnt - 1;
}

void sol() {
    cin >> n >> m;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    // dfs(m);
    int ans = 0;
    // for (int i = 1; i < n; i++) {
    //     if (depcnt[i] == 0)
    //         break;
    //     ans += min(depcnt[i] - 1, d[i].size());
    // }
    // int ans = n;
    cout << dfs(m) << endl;
    return;
    for (int i = 1; i <= n; i++) if (i != m) {
        ans += (G[i].size() > 2);
    }
    ans += G[m].size();
    cout << ans << endl;
}

/*

5 1
1 2
2 3
3 4
4 5

5 3
1 2
2 3
3 4
4 5


7 1
1 2
1 3
2 4
2 5
3 6
3 7
*/

signed main() {
    Koying;
    sol();
    return 0;
}