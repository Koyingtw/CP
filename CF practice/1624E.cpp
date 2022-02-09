// Problem: E. Masha-forgetful
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
string x[MAXN];
pii dp[MAXN][2];
map<string, pii> mp;

void sol()
{
	cin >> n >> m;
	cin.ignore();
	MEM(dp, 0);
	mp.clear();
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		for (int j = 0; j < m - 1; j++) {
			string tmp = "";
			tmp += x[i][j];
			tmp += x[i][j + 1];
			mp[tmp] = {i, j};
		}
		for (int j = 0; j < m - 2; j++) {
			string tmp = "";
			tmp += x[i][j];
			tmp += x[i][j + 1];
			tmp += x[i][j + 2];
			mp[tmp] = {i, j};
		}
	}
	cin >> s;
	
	for (int i = 1; i < m; i++) {
		string ouo = "";
		ouo += s[i - 1];
		ouo += s[i];
		if (i == 1 && mp[ouo].F) {
			dp[i][0] = mp[ouo];
		}
		else if (i > 1 && mp[ouo].F && (dp[i - 2][0].F || dp[i - 2][1].F)) {
			dp[i][0] = mp[ouo];			
		}
		// else if (i > 2 && mp[ouo].F && dp[i - 3][1].F) {
			// dp[i][0] = mp[ouo];			
		// }
		if (i == 1) continue;
		
		ouo = "";
		ouo += s[i - 2];
		ouo += s[i - 1];
		ouo += s[i];
		// put(dp[i - 2][0].F);
		if (i == 2 && mp[ouo].F) {
			dp[i][1] = mp[ouo];
		}
		else if (i > 2 && mp[ouo].F && (dp[i - 3][1].F || dp[i - 3][0].F)) {
			dp[i][1] = mp[ouo];
		}
	}
	
	if (!dp[m - 1][0].F && !dp[m - 1][1].F) {
		cout << -1 << endl;
		return;
	}
	
	vector<tuple<int, int, int>> ans;
	int i = m - 1;
	while (i > 0) {
		// cout << i << endl;
		if (dp[i][1].F) {
			ans.pb({dp[i][1].S, dp[i][1].S + 2, dp[i][1].F});
			i -= 3;
		}
		if (dp[i][0].F) {
			ans.pb({dp[i][0].S, dp[i][0].S + 1, dp[i][0].F});
			i -= 2;
		}
	}
	
	cout << ans.size() << endl;
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		auto[a, b, c] = ans[i];
		cout << a + 1 << " " << b + 1 << " " << c << endl;
	}
	
	// for (int it: v)
		// cout << it << " ";
	// cout << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}