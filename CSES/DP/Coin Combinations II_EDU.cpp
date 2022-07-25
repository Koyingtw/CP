// Problem: Coin Combinations II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1636
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 1000005
#define MAXM 1000005 
int n, x;
int dp[105][MAXN];
int c[105];

void sol() {
    cin >> n >> x;	
    for (int i = 0; i <= n; i++)
    	dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
        	dp[i][j] = dp[i - 1][j];
            if (j - c[i] >= 0)
                dp[i][j] += dp[i][j - c[i]];
	        dp[i][j] %= P;
        }
    }
    
    cout << dp[n][x] << endl;
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