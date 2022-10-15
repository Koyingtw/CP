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
int s[MAXN];
vector<int> G[MAXN];

pii dfs(int i, int paths) {
    // cout << i << endl;
    if (G[i].size() == 0) {
        return pii(paths * s[i], s[i]);
    }

    pii res(0, 0);
    vector<int> v;
    for (int e: G[i]) {
        pii tmp = dfs(e, paths / G[i].size());
        // cout << e << ' ' << tmp.F << ' ' << tmp.S << endl;
        res.F += tmp.F;
        // cmax(res.S, tmp.S);
        v.pb(tmp.S);
    }
    sort(all(v), greater<int>());
    
    // cout << v.size() << ' ' << paths % G[i].siz
    for (int j = 0; j < paths % G[i].size(); j++) {
        res.F += v[j];
    }
    res.S = v[paths % G[i].size()];
    res.S += s[i];
    res.F += s[i] * paths;
    return res;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        G[i].clear();

    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        G[p].pb(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    // dfs(1, m);
    pii ans = dfs(1, m);
    cout << ans.F << endl;
    // cout << dfs(1, m).F << endl;
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