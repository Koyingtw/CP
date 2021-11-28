// Problem: G. 在泥沼中前進
// Contest: Codeforces - 2021 AA 競程 秋季 Level 1 期末測驗
// URL: https://codeforces.com/gym/356593/problem/G
// Memory Limit: 256 MB
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
#define MAXN 2005
#define MAXM 1000005 
int n, m;
vii G[MAXN];
bitset<MAXN> vis;
int dis[MAXN];
int ans = 0;
void dfs(int i, int step)
{
	vis[i] = 1;
	for(pii e: G[i])
	{
		if(!vis[e.F])
		{
			if(step + e.S < 2)
			{
				ans++;
				//cout << i << " " << e.F << endl;
				dfs(e.F, step + e.S);
			}
		}
	}
	//vis[i] = 0;
}

void dijkstra(int i)
{
	MEM(dis, 63);
	dis[i] = 0;
	pqueue<pii, vii, greater<pii>> pq;
	pq.push({i, 0});
	while(pq.size())
	{
		pii now = pq.top();
		pq.pop();
		if(now.S != dis[now.F]) continue;
		for(pii e: G[now.F])
		{
			if(dis[e.F] > dis[now.F] + e.S)
			{
				dis[e.F] = dis[now.F] + e.S;
				pq.push({e.F, dis[e.F]});
			}
		}
	}
}
void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		G[a].pb({b, c});
	}
	for(int i = 1; i <= n; i++)
	{
		vis.reset();
		MEM(dis, 0);
		dijkstra(i);
		for(int j = 1; j <= n; j++)
			ans += (dis[j] < 2);
	}
	put(ans);
	
	
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