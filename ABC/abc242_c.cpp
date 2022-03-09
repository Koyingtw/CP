// Problem: C - 1111gal password
// Contest: AtCoder - AtCoder Beginner Contest 242
// URL: https://atcoder.jp/contests/abc242/tasks/abc242_c
// Memory Limit: 1024 MB
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int dp[MAXM][10];

void sol()
{
	for (int i = 1; i < 10; i++)	
		dp[1][i] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j != 1)
				dp[i][j] += dp[i - 1][j - 1];
			if (j != 9)
				dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= P;
			
		}
	}
	int ans = 0;
	for (int i = 1; i < 10; i++)
		ans += dp[n][i] % P;
	cout << ans % P << endl;
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