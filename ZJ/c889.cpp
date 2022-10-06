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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
bitset<MAXN> vis;
int ans[MAXN];
int cnt = 0, depth = 0;

bool dfs(int i, int dep) {
    vis[i] = true;
    ans[i] = dep % 2;
    cnt += ans[i];
    depth++;

    bool legal = true;
    for (int e: G[i]) {
        if (!vis[e]) {
            legal &= dfs(e, dep + 1);
        }
        else if (ans[e] == ans[i]) {
            legal = false;
        }
    }
    return legal;
}

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    bool legal = true;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cnt = depth = 0;
        if (!vis[i])
            legal &= dfs(i, 0);
        sum += min(cnt, depth - cnt);
    }
   
    cout << sum * legal << endl;
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