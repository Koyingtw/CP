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
#define MAXN 25
#define MAXM 1000005 
int n, m;
int x[MAXN][MAXN];
int dp[MAXN * MAXN][MAXN * MAXN];
int path[5] = {1, 0, -1, 0, 1};
queue<pii> q;
bitset<MAXN> vis[MAXN];
vector<pii> G[MAXN];
bool check(int a, int b)
{
	return (a >= 0 && b >= 0 && a < n && b < n);
}

int f(int a, int b)
{
	return a * n + b;
}
void sol()
{
	cin >> n;
	MEM(dp, 63);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> x[i][j];
			dp[f(i, j)][f(i, j)] = 0;
		}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0, a, b; k < 4; k++)
			{
				a = i + path[k], b = j + path[k + 1];
				if(check(a, b))
				{
					//G[f(i, j)].pb({f(a, b), x[a][b]});
					dp[f(i, j)][f(a, b)] = x[a][b];
				}
			}
		}
	}
	for(int k = 0; k < n * n; k++)
	{
		for(int i = 0; i < n * n; i++)
		{
			for(int j = 0; j < n * n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	
	int t;
	cin >> t;
	while(t--)
	{
		int pos[4];
		for(int i = 0; i < 4; i++) cin >> pos[i];
		for(int i = 0; i < 4; i++) pos[i]--;
		int ans = INF;
		if(pos[0] == pos[2] && pos[1] == pos[3])
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int tmp = dp[f(pos[0], pos[1])][f(i, j)] + x[pos[0]][pos[1]];
				tmp += dp[f(i, j)][f(pos[2], pos[3])];
				tmp -= x[i][j];
				cmin(ans, tmp);
			}
		}
		put(ans);
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