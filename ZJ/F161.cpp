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
vector<int> v;
bitset<MAXN> vis;
int in[MAXN];
int col[MAXN];
int ans = 0;
void dfs(int i, map<int, int> mp, int dep)
{
	vis[i] = true;
	mp[col[i]]++;
	cmax(ans, mp[col[i]]);
	for(int e: G[i])
	{
		if(!vis[e])
		{
			dfs(e, mp, dep);
		}
	}
	vis[i] = false;
}

void sol()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> col[i];
		v.pb(col[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	// cout << v.size() << endl;
	for(int i = 1; i <= n; i++)
	{
		col[i] = lower_bound(v.begin(), v.end(), col[i]) - v.begin();
		// cout << col[i] << endl;	
	}
		
	for(int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		in[b]++;
	}
	queue<int> q;
	map<int, int> mp;
	dfs(0, mp, 1);
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