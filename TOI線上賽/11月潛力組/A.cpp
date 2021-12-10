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
#define MAXN 20
#define MAXM 1000005 
int n, m;
bool G[MAXN][MAXN];

void sol()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> G[i][j];
	}
	int ans = 0;
	for(int mask = 0; mask < (1 << n); mask++)
	{
		int tmp = 0;
		bool yes = 1;
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(G[i][j] && (mask & (1 << i)) && (mask & (1 << j)))
					yes = 0;
			}
		}
		cmax(ans, (yes * (__builtin_popcount(mask))));
	}
	cout << ans << endl;
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