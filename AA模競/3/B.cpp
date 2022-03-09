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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 505
#define MAXM 1000005 
int n, m, c, k;
int x[MAXN];
int s[MAXN][205];
int mn[MAXN];
int dp[205];
vector<pii> G[MAXN];

void sol1() {
	pqueue<pii> pq;
	pq.push({0, 1});
	MEM(mn, 63);
	mn[1] = 0;
	while (pq.size()) {
		pii now = pq.top();
		pq.pop();
		if (mn[now.S] != now.F)
			continue;
		for (pii e: G[now.S]) {
			if (mn[e.F] > now.F + e.S) {
				mn[e.F] = now.F + e.S;
				pq.push({mn[e.F], e.F});
			}
		}
	}
	// for (int i = 2; i <= n; i++) {
		// for (int j = 1; j <= c; j++)
			// s[i][j] += mn[i];
	// }
	MEM(dp, 63);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int l = k; l >= 0; l--) {
			for (int j = 1; j <= c; j++) {
				if (l < j) break;
				cmin(dp[l], dp[l - j] + s[i][j] + j * mn[i]);
			}
		}
		// cout << endl;
	}
	// for (int i = 1; i < k; i++)
		// cout << dp[i] << " ";
	cout << dp[k] << endl;
}

void sol()
{
	cin >> n;
	for (int i = 1, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		G[a].pb({b, c});
		G[b].pb({a, c});
	}
	cin >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> s[i][j];
		}
	}
	cin >> k;
	bool one = 1;
	for (int i = 1; i <= k; i++) {
		cin >> x[i];
		one &= x[i] == 1;
	}
	if (one) {
		sol1();
		return;
	}
		
	
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}