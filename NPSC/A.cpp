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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int g[MAXN];
vector<int> G[MAXN];

bitset<MAXN> vis;

void dfs(int i, int m, int dep)
{
	vis[i] = 1;
	g[i] = dep % m;
	for(int e: G[i])
	{
		if(!vis[e])
			dfs(e, m, dep + 1);
	}
}
bool check()
{
	bool yes = 1;
	for(int i = 1; i <= n; i++)
		for(int e: G[i])
			yes &= (g[i] != g[e]);
			
	return yes;
}
void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	int l = 1, r = MAXN, m = n / 2;
	for(m = 1; m < n; m++)
	{
		//m = (l + r) / 2;
		vis.reset();
		for(int j = 1; j <= n; j++)
		{
			if(!vis[j])
				dfs(1, m, 0);
		}
		if(check())
			break;
	}
	vis.reset();
	//put(m);
	for(int i = 1; i <= n; i++)
		cout << g[i] + 1 << " ";
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
