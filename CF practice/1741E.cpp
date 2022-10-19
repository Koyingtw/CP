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
bool dp[MAXN][2]; // 0: left, 1: right
int x[MAXN];
set<int> edge[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

void dfs(int i) {
    vis[i] = 1;
    for (int j : G[i]) {
        if (!vis[j]) {
            dfs(j);
        }
    }
}

void sol1() {
    cin >> n;
    G[0].clear();
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        dp[i][0] = dp[i][1] = false;
        G[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        if (i + x[i] + 1 <= n + 1)
            G[i].pb(i + x[i] + 1);
        if (i - x[i] - 1 >= 0) 
            G[i - x[i]].pb(i + 1);
    }

    for (int st = 1; st < 2; st++) {
        vis.reset();
        dfs(st);
        if (vis[n + 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        dp[i][0] = dp[i][1] = false;
        edge[i].clear();
    }
    dp[0][0] = dp[0][1] = true;

    for (int i = 1; i <= n; i++) {
        dp[i][0] |= dp[i - 1][0];
        for (int it: edge[i - 1]) {
            dp[i][0] |= dp[it][0];
        }
        if (i - x[i] - 1 >= 0) {
            for (int it: edge[i - x[i] - 1])
                dp[i][1] |= dp[it][0];
            dp[i][1] |= dp[i - x[i] - 1][1];
        }

        if (dp[i][0] && i + x[i] <= n)
            edge[i + x[i]].insert(i);
    }
    bool legal = dp[n][1];

    for (int it: edge[n])
        legal |= dp[it][0];
    cout << (legal ? "YES" : "NO") << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol1();
        }
    }
        
    return 0;
}