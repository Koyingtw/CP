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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];

struct Tarjans {
    int tt, sccId;
    int dep[MAXN], low[MAXN], scc[MAXN];
    bitset<MAXN> inSt;
    stack<int> St;

    void dfs(int i, int pa) {
        dep[i] = low[i] = ++tt;
        inSt[i] = true;
        St.push(i);
        for (int e: G[i]) {
            if (!dep[e]) {
                dfs(e, i);
                cmin(low[i], low[e]);
            }
            else if (inSt[e])
                cmin(low[i], dep[e]);
        }
        if (low[i] == dep[i]) {
            sccId++;
            int p;
            do {
                p = St.top();
                St.pop();
                inSt[p] = false;
                scc[p] = sccId;
            } while (p != i);
        }
    }

    void build() {
        for (int i = 1; i <= n; i++) if (!dep[i])
            dfs(i, i);
    }
} Tarjan;

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    Tarjan.build();

    cout << Tarjan.sccId << endl;
    for (int i = 1; i <= n; i++)
        cout << Tarjan.scc[i] << " \n"[i == n];
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