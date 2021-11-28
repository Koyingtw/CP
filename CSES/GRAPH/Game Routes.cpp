// Problem: Game Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1681
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
const int INF = 0x3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 200005 
int n, m;
int dp[MAXN], in[MAXN];
vector<int> G[MAXN], REVG[MAXN];
bitset<MAXN> vis;
// topo!!!!!!!!

void sol()
{
	cin >> n >> m;
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		G[a].pb(b);
		REVG[b].pb(a);
		in[b]++;
	}
	dp[1] = 1;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!in[i]) q.push(i);
	while(q.size())
	{
		int now = q.front();
		q.pop();
		in[now] = INF;
		for(int e: G[now])
		{
			//if(vis[e]) continue;
			dp[e] += dp[now];
			dp[e] %= P;
			in[e]--;
			if(!in[e])
				q.push(e);
		}
		
	}
	cout << dp[n] << endl;
	//cout << dfs(n) % P << endl;
	//for(int i = 1; i <= n; i++) cerr << dp[i] << (" \n")[i == n];
	//cout << dp[n] % P << endl;
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