#pragma region
#pragma GCC optimize("O3, Ofast, inline")
#pragma GCC target("avx")
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
#define MAXN 10005
#define MAXM 1000005 
int n, m;

int cnt[3][MAXN];// R P S
int g[3][MAXN];
int x[MAXN][3];
bool dp[MAXN][MAXN][3];

string cons = "RPS";

int check(string a, string b)
{
	int sum = 0;
	for(int i = 0; i < a.size(); i++)
	{
		int aa, bb;
		for(int j = 0; j < 3; j++)
		{
			if(a[i] == cons[j]) aa = j;
		}
		for(int j = 0; j < 3; j++)
		{
			if(b[i % m] == cons[j]) bb = j;
		}
		if(aa == (bb + 1) % 3)
			sum--;
		else sum += (aa != bb);
		cout << sum << endl;
	}
	return sum;
}

void sol()
{
	cin >> n >> m;
	cin.ignore();
	string s;
	cin >> s;
	MEM(dp, 0);
	MEM(cnt, 0);
	for(int i = 0; i < s.size(); i++)
	{
		for(int j = 0; j < 3; j++)
			cnt[j][i % m] += (s[i] == cons[j]);
	}
	int sum = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < m; j++)
		{
			g[i][j] = cnt[(i + 2) % 3][j] - cnt[(i + 1) % 3][j];
			// cout << g[i][j] << " ";
		}
		// cout << endl;
	}
	for(int i = 0; i < m; i++)
	{
		int mx = max(g[0][i], max(g[1][i], g[2][i]));
		sum += mx;
		x[i][0] = -(g[0][i] - mx);
		x[i][1] = -(g[1][i] - mx);
		x[i][2] = -(g[2][i] - mx);
	}
	// cout << endl;
	// for(int i = 0; i < m; i++)
	// {
		// for(int j = 0; j < 3; j++)
		// {
			// cout << x[i][j] << " ";
		// }
		// cout << endl;
	// }
	if(sum <= 0)
	{
		cout << -1 << endl;
		cout << "impossible" << endl;
		return;
	}
	// cout << sum << endl << endl;
	// dp[0][0][0] = 1;
	// dp[0][0][1] = 1;
	// dp[0][0][2] = 1;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[i][x[i][j]][j] = 1;
			for(int k = sum - x[i][j]; k >= 0; k--)
			{
				for(int l = 0; l < 3; l++)
				{
					if(i)
						dp[i][k + x[i][j]][j] |= dp[i - 1][k][l];
				}
			}		
		}
	}
	pii mx = {0, 0};
	for(int i = sum - 1; i >= 0; i--)
	{
		bool doo = 1;
		for(int j = 0; j < 3 && doo; j++)
		{
			if(dp[m - 1][i][j])
			{
				// cout << sum - i << " " << j << endl;
				mx = {i, j};
				// cout << "ouo" << endl;
				doo = 0;
			}
			// cout << dp[m - 1][i][j] << " ";
		}
		if(!doo) break;
		// cout << endl;
	}
	string ans;
	cout << sum - mx.F << endl;
	for(int i = m - 1; i; i--)
	{
		ans += cons[mx.S];
		mx.F -= x[i][mx.S];
		// cout << mx.F << endl;
		for(int j = 0; j < 3; j++)
		{
			if(mx.F >= x[i - 1][j] && dp[i - 1][mx.F][j])
			{
				mx.S = j;
				break;
			}
		}
	}
	ans += cons[mx.S];
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	// cout << x[0][0] << endl;
	// cout << check(s, ans) << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}