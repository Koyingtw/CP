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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
int sz[MAXN], dp[MAXN], ans;

void dfs1(int i, int pa) {
    int sum = 0;
    for (int e: G[i]) if (e != pa) {
        
        dfs1(e, i);
        sum += dp[e];
        sz[i] += sz[e] + 1;
    }


    for (int e: G[i]) if (e != pa) {
        cmax(dp[i], sum - dp[e] + sz[e]);
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        sz[i] = 0;
        dp[i] = 0;
    }

    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs1(1, 0);
    cout << dp[1] << endl;
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