// Problem: Forest Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1652
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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
char x[MAXN][MAXN];
int pre[MAXN][MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> x[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			pre[i][j] += (x[i][j] == '*');
			//cout << pre[i][j] << " ";
		}
		//cout << endl;
	}
	int in[4];
	while(m--)
	{
		for(int i = 0; i < 4; i++)
		{
			cin >> in[i];
		}
			
		int ans = pre[in[2]][in[3]];
		//put(ans);
		ans -= pre[in[0] - 1][in[3]];
		ans -= pre[in[2]][in[1] - 1];
		ans += pre[in[0] - 1][in[1] - 1];
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