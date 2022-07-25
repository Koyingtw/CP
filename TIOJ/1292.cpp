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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 10005
#define MAXM 1000005 
int n, m, ans = 0;
int deg[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis, tag;

void dfs(int i) {
	vis[i] = true;
	int cnt = 0;
	
	for (auto e: G[i]) {
		if (!vis[e]) {
			dfs(e);
			cnt++;
			
			if (!tag[e]) {
				ans += !tag[i];
				tag[i] = true;
			}
		}
	}
}

void sol() {
	cin >> n;
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	
	//
	dfs(1);
	cout << ans << endl;
	
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}