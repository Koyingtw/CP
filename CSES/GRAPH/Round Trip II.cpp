// Problem: Round Trip II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1678/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
vector<int> G[MAXN], ans;
bitset<MAXN> vis, rout;
int fin = 0;
int aa = 0;
void dfs(int i)
{
	vis[i] = true;
	rout[i] = true;
	// put(i)
	for(int e: G[i])
	{
		if(fin) break;
		if(rout[e])
		{
			fin = e;
			aa = e;
			// cout << e << endl;
			ans.pb(e);
			return;
		}
		else
		{
			// cout << i << " " << e << endl;
			dfs(e);
			if(fin > 0) 
			{
				ans.pb(e);
				if(i == fin)
					fin = -1;
				return;
			}
		}
	}
	rout[i] = false;
}

void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		// G[b].pb(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			rout.reset();
			dfs(i);		
		}
		if(fin) 
		{
			ans.pb(aa);
			// put(i);
			break;
		}
	}
	reverse(all(ans));
	if(!ans.size())
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << ans.size() << endl;
	for(int it: ans) cout << it << " ";
	cout << endl;
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