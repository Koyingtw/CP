// Problem: Elevator Rides
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1653
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
#define MAXM 10000005 
int n, m;
pii dp[MAXM];
int x[25];
void sol()
{
	cin >> n >> m;
	MEM(dp, 63);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		dp[0] = {1, 0};
		dp[(1 << i)] = {1, x[i]};
	}
	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((i & (1 << j))) continue;
			pii tmp = dp[i];
			if(dp[i].S + x[j] > m)
			{
				tmp.F++;
				tmp.S = x[j];
			}
			else tmp.S += x[j];
			if(dp[i + (1 << j)].F > tmp.F) dp[i + (1 << j)] = tmp;
			else if(dp[i + (1 << j)].S > tmp.S) dp[i + (1 << j)] = tmp;
		}
	}
	int ans = INF;
	
	put(dp[(1 << n) - 1].F);
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