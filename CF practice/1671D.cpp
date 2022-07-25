// Problem: D. Insert a Progression
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol() {
	cin >> n >> m;
	int mn = INF, mx = 0;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cmin(mn, x[i]);
		cmax(mx, x[i]);
		if (i)
			ans += abs(x[i] - x[i - 1]);
	}
	if (mn > 1) {
		int tmp = INF;
		for (int i = 0; i < n; i++) {
			cmin(tmp, abs(x[i] - 1) * 2);
		}
		cmin(tmp, abs(x[0] - 1));
		cmin(tmp, abs(x[n - 1] - 1));
		ans += tmp;
	}
	if (mx < m) {
		int tmp = INF;
		for (int i = 0; i < n; i++) {
			cmin(tmp, abs(x[i] - m) * 2);
		}
		cmin(tmp, abs(x[0] - m));
		cmin(tmp, abs(x[n - 1] - m));
		ans += tmp;
	}
	cout << ans << endl; 
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