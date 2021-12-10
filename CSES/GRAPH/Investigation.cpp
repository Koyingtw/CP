// Problem: Investigation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1202
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
vector<pii> G[MAXN];
struct Node
{
	int dis, cnt, mn, mx; 
};
Node ans[MAXN];
bitset<MAXN> vis;

void init()
{
	for(int i = 0; i < MAXN; i++)
		ans[i] = {INF, 0, 0, 0};
}

void dijkstra()
{
	priority_queue<pii> pq;
	ans[1] = {0, 1, 0, 0};
	pq.push({1, 0});
	while(pq.size())
	{
		pii now = pq.top();
		pq.pop();
		for(pii e: G[now.F])
		{
			if(ans[e.F].dis > now.S + e.S)
			{
				ans[e.F].dis = now.S + e.S;
				ans[e.F].mn = ans[now.F].mn + 1;
				ans[e.F].mx = ans[now.F].mx + 1;
				ans[e.F].cnt = ans[now.F].cnt;
				pq.push({e.F, ans[e.F].dis});
			}
			else if(ans[e.F].dis == now.S + e.S) 
			{
				ans[e.F].cnt = (ans[e.F].cnt + ans[now.F].cnt) % P;
				cmin(ans[e.F].mn, ans[now.F].mn + 1);
				cmax(ans[e.F].mx, ans[now.F].mx + 1);
				// pq.push({e.F, ans[e.F].dis});
			}
		}
	}
	return;
}

void sol()
{
	init();
	cin >> n >> m;
	for(int i = 0, u, v, val; i < m; i++)
	{
		cin >> u >> v >> val;
		G[u].pb({v, val});
	}
	dijkstra();
	cout << ans[n].dis << " " << ans[n].cnt << " " << ans[n].mn << " " << ans[n].mx << endl;
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