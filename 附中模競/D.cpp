// Problem: D. Francium 賺多少 (Flip)
// Contest: Codeforces - 110 師大附中／延平中學 競技程式讀書會 模擬競賽 I
// URL: https://codeforces.com/gym/351808/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
#define MAXN 50005
#define MAXM 10
int n, m, k;
int x[MAXN][MAXM];
int dp[MAXN][MAXM];

void sol1()
{
	int tmp = x[0][0], sum = 0;
	for(int i = 1; i < n; i++)
	{
		if(i == n - 1 || x[i][0] < x[i][0])
	}
	cout << mx << endl;
	
}

void sol3()
{
	
}

void sol()
{
	cin >> n >> m >> k;
	bool one = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> x[i][j];
		}
	for(int j = 0; j < m; j++)
		for(int i = 1; i < n; i++)
		{
			if(x[i - 1][j] > x[i][j]) one = 0;
		}
	// if(m == k)
	// {
		// cout << 0 << endl;
// 		
	// }
	// if(one)
	// {
		// cout << 0 << endl;
		// return;
	// }
	if(m == 1)
	{
		sol1();
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