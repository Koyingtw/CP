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
#define MAXN 5005
#define MAXM 1000005 
int n, m;
double dp[MAXN][2]; // reach, exists
vector<int> G[MAXN];
double g[MAXN][MAXN];

void pre() {
    for (int i = 1; i < MAXN; i++) {
        g[i][1] = 1.0 / i;
        for (int j = 0)
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    dp[1][0] = 1;

    for (int i = 1; i < n; i++) {
        double total = G[i].size();
        // for (auto e: G[i]) {
        //     total += dp[i][1];
        // }
        double tmp = 1.0 / total;
        double tmp2 = 1.0 / total;
        for (int j = 1; j <= ((int)G[i].size() - 1) / 2; j++) {
            tmp += (G[i].size() - 1 - 2 * j + 2) * tmp2 * (1.0 / (total - 2 * j));
            tmp2 *= (1.0 / (total - 2 * j));
        }

        for (auto e: G[i]) {
            cmax(dp[e][0], dp[i][0] * tmp);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dp[i][0] << ' ';

    cout << fixed << setprecision(10) << dp[n][0] << endl;
} 

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}