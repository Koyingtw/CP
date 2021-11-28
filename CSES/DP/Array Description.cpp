// Problem: Array Description
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1746
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int dp[MAXN][105];
int x[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		if(x[i] == 0 && i == 0)
		{
			for(int j = 1; j <= m; j++) dp[i][j] = 1;
		}
		else if(x[i] == 0)
		{
			for(int j = 1; j <= m; j++)
			{
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];	
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= P;
			}
		}
		else if(i == 0) dp[i][x[i]] = 1;
		else
		{
			dp[i][x[i]] = dp[i - 1][x[i]] + dp[i - 1][x[i] + 1] + dp[i - 1][x[i] - 1];
			dp[i][x[i]] %= P;
		}
	}
	int sum = 0;
	for(int i = 1; i <= m; i++) sum += dp[n - 1][i];
	put(sum % P);
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