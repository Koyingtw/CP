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
#define MAXN 2005
#define MAXM 1000005 
int n, m;
int x[MAXN];
vector<int> G[MAXN];

pii dfs(int i, int pa) { // mx, ans
    int mx = 0;
    int ans = 0;
    for (int e: G[i]) if (e != pa) {
        auto tmp = dfs(e, i);
        cmax(mx, tmp.F);
        ans += tmp.S;
    }
    ans += x[i];
    if (x[i] > mx + 1) {
        ans = x[i] - 1;
    }
    mx += x[i];
    cout << ans << endl;
    return {mx, ans};
}

pair<bitset<MAXN>, bitset<MAXN>> dfs1(int i, int pa) {
    pair<bitset<MAXN>, bitset<MAXN>> res;
    res.F[x[i]] = true;
    for (int e: G[i]) if (e != pa) {
        auto tmp = dfs1(e, i);
        res.F |= tmp.F;
        res.S |= tmp.S;
    }
    res.S |= res.F;
    res.S |= (res.F << x[i]);
    return res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    auto ans = dfs1(1, 1).S;
    for (int i = 1; i <= 2 * n + 1; i++) {
        if (!ans[i]) {
            cout << i << endl;
            return;
        }
    }
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