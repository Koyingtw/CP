// Problem: E. 聒噪病毒 (Garrulous)
// Contest: Codeforces - 110 師大附中／延平中學 競技程式讀書會 模擬競賽 I
// URL: https://codeforces.com/gym/351808/problem/E
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
#define MAXN 500005
#define MAXM 500005 
int n, m;
vector<int> G[MAXN];
bitset<MAXN> DD;
int last[MAXN], cnt[MAXN];
void sol()
{
	cin >> n >> m;
	int k, q;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	cin >> k;
	for(int i = 1; i <= n; i++) last[i] = -INF;
	queue<pii> bfs;
	for(int i = 0, a; i < k; i++)
	{
		cin >> a;
		DD[a] = 1;
		last[a] = 0;
		bfs.push({a, 0});
		cnt[0]++;
	}
	cin >> q;
	int a, mx = 0;
	vector<int> v;
	while(q--)
	{
		cin >> a;
		cmax(mx, a);
		v.pb(a);
	}
	//put(mx);
	while(bfs.size() && bfs.front().S <= mx)
	{
		pii now = bfs.front();
		bfs.pop();
		last[now.F] = now.S;
		for(int e: G[now.F])
		{
			if(last[e] >= now.S - 1)
				continue;
			else 
			{
				cnt[now.S + 1]++;
				bfs.push({e, now.S + 1});
				last[e] = now.S + 1;
				//cout << e << " " << now.S + 1 << endl; 
			}
		}
	}
	for(int it: v) 
	{
		if(it <= n)
			cout << cnt[it] << endl;
		else cout << 0 << endl;
		
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