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
#define MAXN 10005
#define MAXM 1000005 
int n, m, tt = 1, id = 1;
int in[MAXN], SCC[MAXN], D[MAXN], L[MAXN], cnt[MAXN], dp[MAXN];
vector<int> G[MAXN], G2[MAXN];
bitset<MAXN> inSt;
stack<int> St;

void dfs(int i)
{
	D[i] = L[i] = tt++;
	St.push(i);
	inSt[i] = true;
	
	for(int e: G[i])
	{
		if(!D[e])
		{
			dfs(e);
			cmin(L[i], L[e]);
		}
		else if(inSt[e])
			cmin(L[i], D[e]);
	}
	if(D[i] == L[i])
	{
		int a = -1;
		do
		{
			a = St.top();
			St.pop();
			inSt[a] = false;
			SCC[a] = id;
			cnt[id]++;
		}while(a != i);
		id++;
	}
}

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		G[i].clear(), G2[i].clear();
	inSt.reset();
	MEM(D, 0);
	MEM(L, 0);
	MEM(dp, 0);
	MEM(cnt, 0);
	MEM(in, 0);
	tt = 1;
	id = 1;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		// G[b].pb(a);
	}
	for(int i = 1; i <= n; i++)
		if(!D[i]) dfs(i);
	
	for(int i = 1; i <= n; i++)
	{
		// cout << SCC[i] << " ";
		for(int e: G[i])
			if(SCC[i] != SCC[e])
				G2[SCC[i]].pb(SCC[e]);
	}
	// cout << endl;
	for(int i = 1; i < id; i++)
	{
		sort(all(G2[i]));
		G2[i].erase(unique(all(G2[i])), G2[i].end());
	}
	for(int i = 1; i < id; i++)
	{
		for(int e: G2[i])
			in[e]++;
	}
	queue<int> q;
	for(int i = 1; i < id; i++)
	{
		if(!in[i])
			q.push(i);
		// cout << cnt[i] << endl;
	}
	// for(int i = 1; i < id; i++)
	// {
		// for(int e: G2[i])
			// cout << e << " ";
		// cout << endl;
	// }
	int ans = 0;
	while(q.size())
	{
		int now = q.front();
		q.pop();
		in[now] = -INF;
		cmax(ans, dp[now]);
		// cout << now << endl;
		for(int e: G2[now])
		{
			cmax(dp[e], cnt[e] + cnt[now]);
			in[e]--;
			if(!in[e])
			{
				q.push(e);
				in[e] = -INF;
			}
		}
	}
	cout << ans << endl;
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