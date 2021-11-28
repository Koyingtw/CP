// Problem: I. 優美圖
// Contest: Codeforces - 2021 AA 競程 Level 1 春季期末考
// URL: https://codeforces.com/gym/331434/problem/I
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
int deg[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		deg[a]++, deg[b]++;
	}
	int mn = INF;
	multiset<int> st;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i]) 
		{
			st.insert(deg[i]);
			cmin(mn, deg[i]);
		}
	}
	int ans = mn;
	multiset<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == mn)
			q.insert(i);
	}
	while(q.size())
	{
		int now = *q.begin();
		q.erase(q.begin());
		//cout << now << endl;
		if(deg[now] == INF) continue;
		st.erase(st.find(deg[now]));
		cmax(ans, deg[now]);
		deg[now] = INF;
		for(int e: G[now])
		{
			st.erase(st.find(deg[e]));
			deg[e]--;
			st.insert(deg[e]);
			if(deg[e] <= *st.begin())
			{
				q.insert(e);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] < 1e9) cmax(ans, deg[i]);
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