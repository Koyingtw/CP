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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
int go[MAXN];
int u[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;
int sum = 0;
int under(int i)
{
	vis[i] = 1;
	// put(i);
	int cnt = 0;
	for(int e: G[i])	
	{
		if(!vis[e]) cnt += under(e);
	}
	u[i] = cnt;
	return cnt + (go[i] > 0);
}

void sol()
{
	cin >> n >> m;
	for(int i = 1, a, b, c; i <= n; i++)
	{
		cin >> a;
		while(a--)
		{
			cin >> b;
			G[i].pb(b);
			G[b].pb(i);
		}
	}
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		cin >> go[i];
		sum += (go[i] > 0);
		if(g[i] > 0) v.pb(i);
	}
	vis.reset();
	under(1);
	for(int i = 1; i <= n; i++)
		cout << u[i] << " ";
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