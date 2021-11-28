// Problem: J. 裸背包問題 2
// Contest: Codeforces - 2021 AA 競程 秋季 Level 1 期末測驗
// URL: https://codeforces.com/gym/356593/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
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
#define MAXN 105
#define MAXM 100005 
int n, m;
int dp[MAXN][MAXM];
int fa[MAXN][MAXM];
pii x[MAXN];
void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i].F >> x[i].S;
	int t, q;
	MEM(dp, 0);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= MAXN; j++) dp[i][j] = dp[i - 1][j];
		for(int j = x[i].F; j <= MAXM; j++)
		{
			if(dp[i][j] < dp[i - 1][j - x[i].F] + x[i].F)
			{
				cmax(dp[i][j], dp[i - 1][j - x[i].F] + x[i].S);
			}
		}
	}
	// for(int i = 0; i < 10; i++) cout << dp[n][i] << " ";
	// cout << endl;
	cin >> t;
	while(t--)
	{
		cin >> q;
		pii mx = {0, 0};
		for(int i = q; i >= 0; i--)
		{
			if(dp[n][i] > mx.F)
				mx = {dp[n][i], i};
		}
		//put(mx.S)
		if(mx.F)
		{
			string mnans;
			for(int i = 0; i < n; i++) mnans += "1";
			for(int i = q; i >= 0; i--)
			{
				if(dp[n][i] == mx.F)
				{
					string ans;
					int now = i;
					for(int j = n; j; j--)
					{
						if(x[j].F <= now && dp[j - 1][now - x[j].F] == dp[j][now] - x[j].S)
						{
							ans += '1';
							now -= x[j].F;
						}
						else
							ans += '0';
						//put(now)
					}
					reverse(ans.begin(), ans.end());
					cmin(mnans, ans);
				}
			}
			//cout << now << endl;
			cout << mnans << endl;
		}
		else
		{
			for(int i = 0; i < n; i++) cout << "0";
			cout << endl;
		} 
			
		
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