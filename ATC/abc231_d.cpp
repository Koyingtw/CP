// Problem: D - Neighbors
// Contest: AtCoder - Panasonic Programming Contest 2021(AtCoder Beginner Contest 231)
// URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
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
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int in[MAXN];
vector<int> G[MAXN];
vector<int> ans;
bitset<MAXN> vis;
bool chk = 1;

void dfs(int i)
{
	vis[i] = true;
	ans.pb(i);
	for(int e: G[i])
	{
		if(vis[e])
			chk = 0;
		else 
			dfs(e);
	}
}

void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		in[a]++;
		in[b]++;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(in[i] > 2)					
		{
			cout << "No" << endl;
			return;
		}
		if(in[i] == 0) ans.pb(i);
		if(in[i] == 1 && !vis[i])
		{
			dfs(i);
		}
	}
	if(ans.size() == n)
		cout << "Yes" << endl;
	else cout << "No" << endl;
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