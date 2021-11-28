// Problem: I. 施工危險，請勿進入
// Contest: Codeforces - 2021 AA 競程 秋季 Level 1 期末測驗
// URL: https://codeforces.com/gym/356593/problem/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int P = 998244353;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int dp[MAXN][MAXN], back[MAXN][MAXN];
string s[MAXN];
void sol()
{
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++)
		cin >> s[i];
	dp[0][0] = 1;
	for(int i = 1; i < n; i++)
		dp[0][i] = s[0][i] == '.', dp[i][0] = s[i][0] == '.';
	back[n - 1][n - 1] = 1;
	for(int i = 0; i < n; i++)
		back[n - 1][i] = s[n - 1][i] == '.', back[i][n - 1] = s[i][n - 1] == '.';
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			dp[i][j] = (s[i][j] == '.') * (dp[i - 1][j] + dp[i][j - 1]);
			dp[i][j] %= P;
		}
	}
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = n - 2; j >= 0; j--)
		{
			back[i][j] = (s[i][j] == '.') * (back[i + 1][j] + back[i][j + 1]);
			back[i][j] %= P;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << back[i][j] << " ";
		cout << endl;
	}
	int q, a, b;
	cin >> q;
	while(q--)
	{
		cin >> a >> b;
		a--, b--;
		cout << ((dp[n - 1][n - 1] - ((dp[a][b] * back[a][b]) % P)) + P) % P << endl;
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