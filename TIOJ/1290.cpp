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
int st, fin;
int ans[MAXN];
vii G[MAXN];
pqueue<pii, vii, greater<pii>> pq;
bool yes = 0;
void dijkstra()
{
	ans[st] = 0;
	pq.push({st, 0});
	while(pq.size())
	{
		pii now = pq.top();
		pq.pop();
		if(now.F == fin) yes = 1;
		//put(now.F);
		if(ans[now.F] != now.S)
		{
			continue;
		} 
		for(pii e: G[now.F])
		{
			if(ans[e.F] > now.S + e.S)
			{
				ans[e.F] = now.S + e.S;
				//dis[i][now.F] = INF;
				pq.push({e.F, ans[e.F]});
				//cout << i << " " << dis[st][i] << endl;
			}
		}
	}
}
void SFPA()
{
	ans[st] = 0;
	bitset<MAXN> inque; 
	queue<int> q;
	q.push(st);
	while(q.size())
	{
		int now = q.front();
		q.pop();
		inque[now] = 0;
		for(pii e: G[now])
		{
			if(ans[e.F] > ans[now] + e.S)
			{
				ans[e.F] = ans[now] + e.S;
				if(!inque[e.F])
				{
					q.push(e.F);
					inque[e.F] = 1;
				}
			}
		}		
	}
}

void sol()
{
	while(cin >> n >> m)
	{
		MEM(ans, 63);
		cin >> st >> fin;
		for(int i = 1; i <= n; i++)
			G[i].clear();
		for(int i = 0, a, b, c; i < m; i++)
		{
			cin >> a >> b >> c;
			G[a].pb({b, c});
			G[b].pb({a, c});		
	
		}
		//SFPA();	
		dijkstra();
		if(ans[fin] == ans[0]) cout << "He is very hot" << endl;
		else cout << ans[fin] << endl;
		// for(int i = 1; i <= n; i++)	cout << ans[i] << " ";
		// cout << endl;	
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