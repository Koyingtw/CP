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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int deg[MAXN];
vector<int> G[MAXN], g[MAXN];
struct E {
	int F, S, id;
} x[MAXN];


void sol()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		deg[i] = 0, g[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> x[i].F >> x[i].S;
		deg[x[i].F]++;
		deg[x[i].S]++;
		g[x[i].S].pb(i);
		g[x[i].F].pb(i);
		x[i].id = i;
	}
	
	set<int> s;
	for (int i = 0; i < n; i++)
		G[i].clear();
	
	for (int i = 0; i < n; i++) {
		if (deg[x[i].F] > 2 || deg[x[i].S] > 2) {
			// cout << "Impossible" << endl;
			// return;
		}
		for (int u: g[x[i].F]) {
			if (u != i)
				G[i].pb(u);
		}
		for (int u: g[x[i].S]) {
			if (u != i)
				G[i].pb(u);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int e: G[i])
			cout << e << " ";
		cout << endl;
	}
	
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