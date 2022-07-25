// Problem: String Removals
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1149/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int last[26], dp[MAXN];

void sol() {
	string s;
	cin >> s;
	
	int sum = 1;
	dp[0] = 1;
	last[s[0] - 'a'] = 1;
	for (int i = 1; i < s.size(); i++) {
		dp[i] = dp[i - 1] * 2 - last[s[i] - 'a'] + 1;
		last[s[i] - 'a'] += dp[i];
		dp[i] %= P;
		// cout << dp[i] << " ";
	}
	cout << dp[s.size() - 1] << endl;
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