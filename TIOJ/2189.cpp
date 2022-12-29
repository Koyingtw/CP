#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
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
array<int, 2> ans;
bitset<MAXN> vis;

array<int, 2> dfs(int i, int dep) {
    array<int, 2> res = {dep, dep};
    vis[i] = true;

    for (auto e: G[i]) {
        if (vis[e.F])
            continue;
        
        auto tmp = dfs(e.F, dep + e.S);

        vector<int> tmpans {ans[0], ans[1]};
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmpans.eb(res[j] + tmp[k] - 2 * dep);
            }
        }
        sort(all(tmpans), greater<>());
        tmpans.erase(unique(all(tmpans)), tmpans.end());
        if (tmpans.size() > 1)
            ans = {tmpans[0], tmpans[1]};
        else
            ans = {tmpans[0], tmpans[0]};


        vector<int> v {res[0], res[1], tmp[0], tmp[1]};
        sort(all(v), greater<>());
        v.erase(unique(all(v)), v.end());
        if (v.size() > 1)
            res = {v[0], v[1]};
        else
            res = {v[0], v[0]};
    }
    return res;
}   

void sol() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        G[a].eb(b, c);
        G[b].eb(a, c);
    }

    dfs(0, 0);
    cout << ans[1] << endl;
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