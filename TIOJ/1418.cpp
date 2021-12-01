#pragma region
#pragma GCC optimize("O3")
#include <iostream>
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
double dp[1 << 22];
int x[25][25];

int DP(int mask)
{
	if(dp[mask] != -1) return dp[mask];
	int mn = INF;
	for(int i = 0; i < n - 2; i++)
	{
		if(!((1 << i) & mask)) continue;
		for(int j = i + 1; j < n - 1; j++)
		{
			if(!((1 << j) & mask)) continue;
			for(int k = j + 1; k < n; k++)
			{
				if(!((1 << k) & mask)) continue;
				cmin(mn, DP(mask ^ (1 << i) ^ (1 << j) ^ (1 << k)) + x[i][j] + x[i][k] + x[j][k]);
			}
		}
    	break;
	}
	return dp[mask] = mn;
}

void sol()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> x[i][j];
	for(int i = 0; i < (1 << n); i++)
		dp[i] = -1;
	dp[0] = 0;
	
	cout << DP((1 << n) - 1) << endl;
	
}

signed main()
{
    Weakoying;
    int t = 1;
    cin >> t;
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}