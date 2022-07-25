#pragma GCC optimize("O3")
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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int dp[MAXN][2];
int in[MAXN];
pii insum[MAXN];
vector<pii> G[MAXN], GG[MAXN];

bool cmp(pii a, pii b) {
	if (G[a.S][0].S >= a.F && G[b.S][0].S >= b.F)
		return G[a.S][0].S > G[b.S][0].S;
	else
		return G[a.S][0].S > a.F;
}

void dfs(int i) {
	for (pii e: G[i]) {
		dp[i][0] = max(dp[e.F][1], dp[e.F][0]);
		dp[i][1] = dp[e.F][0] + e.S;
	}
}

void sol() {
	cin >> n;
	for (int i = 1, a, b; i <= n; i++) {
		insum[i].S = i;
		cin >> a >> b;
		G[i].pb({a, b});
		GG[a].pb({i, b});
		// in[i]++;
		insum[a].F += b;
	}
	sort(insum + 1, insum + n + 1);
	
	bitset<MAXN> vis;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int now = insum[i].S;
		DB(now);
		if (!vis[G[now][0].F]) {
			ans += G[now][0].S;
			vis[now] = true;
		}
	}
	
	// for (int i = 0)
	
	cout << ans << endl;
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