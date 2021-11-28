#pragma region
#pragma optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
vector<pii> G[MAXN], REV[MAXN];
int dis[MAXN];
pqueue<pii, vector<pii>, greater<pii>> pq;
bitset<MAXN> vis;
int viscnt = 0;
void dijkstra(int start)
{
	MEM(dis, 63);
	dis[start] = 0;
	pq.push({start, 0});
	while(pq.size())
	{
		pii now = pq.top();
		pq.pop();
		if(!vis[now.F])
		{
			viscnt++;
			vis[now.F] = 1;
		}
		if(dis[now.F] != now.S) continue;
		for(pii e: G[now.F])
		{
			if(dis[e.F] > now.S + e.S)
			{
				dis[e.F] = now.S + e.S;
				pq.push({e.F, dis[e.F]});
			}
		}
	}
}

void revdijkstra(int start)
{
	MEM(dis, 63);
	dis[start] = 0;
	pq.push({start, 0});
	while(pq.size())
	{
		pii now = pq.top();
		pq.pop();
		if(!vis[now.F])
		{
			viscnt++;
			vis[now.F] = 1;
		}
		if(dis[now.F] != now.S) continue;
		for(pii e: REV[now.F])
		{
			if(dis[e.F] > now.S + e.S)
			{
				dis[e.F] = now.S + e.S;
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
		REV[b].pb({a, c});
	}
	ll ans = 0;
	vis.reset();
	viscnt = 0;
	dijkstra(1);
	if(viscnt != n)
	{
		cout << 0 << endl;
		return;
	}
	for(int i = 1; i <= n; i++)	ans += dis[i];
	vis.reset();
	viscnt = 0;
	revdijkstra(1);
	if(viscnt != n)
	{
		cout << 0 << endl;
		return;
	}
	for(int i = 1; i <= n; i++)	ans += dis[i];
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