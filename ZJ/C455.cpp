#pragma region
#pragma optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXX 100005
#define MAXY 100005
#define MAXM 230005 
int n, p, q, k;
vector<int> G[MAXX];
bitset<MAXY> vis;
int mx[MAXX], my[MAXY];
bool dfs(int x)
{
	for(int y: G[x])
	{
		if(!vis[y])
		{
			vis[y] = true;
			
			if(my[y] < 0 || dfs(my[y]))
			{
				mx[x] = y;
				my[y] = x;
				return true;
			}
		}
	}
	return false;
}


int match()
{
	MEM(mx, -1);
	MEM(my, -1);
	int cnt = 0;
	for(int x = 1; x <= p; x++)
	{
		if(mx[x] < 0)
		{
			vis.reset();
			if(dfs(x)) cnt++;
		}
	}
	return cnt;
}

void sol()
{
	cin >> p >> q >> k;
	for(int i = 0; i < MAXX; i++)
		G[i].clear();
	for(int i = 0, a, b; i < k; i++)	
	{
		cin >> a >> b;
		G[a].pb(b);
	}
	cout << match() << endl;
	
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