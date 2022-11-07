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
#define MAXN 100005
#define MAXM 1000005 
int n, m, p, q, k;
vector<int> G[MAXN];
bitset<MAXN> vis;
int px[MAXN], py[MAXN];

bool dfs(int i) {
    for (int e: G[i]) {
        if (!vis[e]) {
            vis[e] = true;
            if (py[e] < 0 || dfs(py[e])) {
                py[e] = i;
                px[i] = e;
                return true;
            }
        }
    }
    return false;
}

int match() {
    MEM(px, -1);
    MEM(py, -1);
    int res = 0;
    for (int i = 1; i <= p; i++) {
        if (px[i] < 0) {
            vis.reset();
            res += dfs(i);
        }
    }
    return res;
}

void sol() {
    cin >> p >> q >> k;
    for (int i = 1; i < MAXN; i++)
        G[i].clear();
    for (int i = 0, a, b; i < k; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    cout << match() << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    cin >> t;
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}