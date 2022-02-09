#pragma region
#pragma optimize("O3")
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
int n, m, K;

void sol()
{
	cin >> K >> n >> m;
	int x[n + 1][m + 1], pre[n + 1][m + 1];
	MEM(pre, 0);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> x[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x[i][j];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int k = i; k <= n; k++)
		{
			set<int> st;
			for(int j = 1; j <= m; j++)
			{
				int tmp = pre[k][j] - pre[i - 1][j];
				// cout << tmp << endl;
				if(tmp <= K) cmax(ans, tmp);
				if(st.size())
				{
					if(st.lower_bound(tmp - K) != st.end())
					{
						int F = *(st.lower_bound(tmp - K));
						if(tmp - F <= K)
						{
							cmax(ans, tmp - F);
						}
						
					}
				}
				st.insert(tmp);
			}
		}
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