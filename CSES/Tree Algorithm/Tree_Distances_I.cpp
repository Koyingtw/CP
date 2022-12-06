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
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
int ans[MAXN], mxchd[MAXN];

int dfs(int i, int pa, int mx, int dep) {
    int res = 0;
    cmax(ans[i], mx);
    for (int e: G[i]) if (e != pa) {
        int tmp = dfs(e, i, max(mx, res - dep) + 1, dep + 1);
        cmax(res, tmp);
    }
    reverse(all(G[i]));

    cmax(ans[i], max(dep, res - dep));
    return max(dep, res);
}

void sol() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1, 1, 0, 0);
    dfs(1, 1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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