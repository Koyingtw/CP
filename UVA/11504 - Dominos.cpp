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
int cnt[MAXN];

struct Tarjan_SCC {
    int low[MAXN], dep[MAXN], scc[MAXN];
    int sccID = 0, timestamp = 0;
    stack<int> St;
    bitset<MAXN> inSt;

    void dfs(int i, int fa) {
        low[i] = dep[i] = ++timestamp;
        St.push(i);
        inSt[i] = true;

        for (int e: G[i]) {            
            if (!dep[e]) {
                dfs(e, i);
                cmin(low[i], low[e]);
            }
            else if (inSt[e])
                cmin(low[i], dep[e]);
        }

        if (low[i] == dep[i]) {
            sccID++;
            int x;
            do {
                x = St.top();
                St.pop();
                inSt[x] = false;
                scc[x] = sccID;
            } while (x != i);
        }
    }

    int main() {
        for (int i = 1; i <= n; i++) {
            low[i] = dep[i] = scc[i] = 0;
            inSt[i] = false;
        }

        timestamp = sccID = 0;

        while (St.size())
            St.pop();

        for (int i = 1; i <= n; i++)
            if (!dep[i])
                dfs(i, i);
        return sccID;
    }
} FindSCC;

struct Kosaraju {
    vector<int> revG[MAXN];
    vector<int> leave;
    bitset<MAXN> vis;
    int sccID, scc[MAXN];

    void dfs1(int i) {
        vis[i] = true;
        for (int e: revG[i]) {
            if (!vis[e])
                dfs1(e);
        }
        leave.pb(i);
    }

    void dfs2(int i) {
        scc[i] = sccID;
        for (int e: G[i]) {
            if (!scc[e]) {
                dfs2(e);
            } 
        }
    }

    void main() {
        for (int i = 1; i <= n; i++) {
            revG[i].clear();
            scc[i] = 0;
        }
        leave.clear();
        sccID = 0;

        for (int i = 1; i <= n; i++) {
            for (int e: G[i])
                revG[e].pb(i);
        }

        auto reset_bitset = [&]() {
            for (int i = 1; i <= n; i++)
                vis[i] = false;
        };
  
        reset_bitset();
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                dfs1(i);
        }

        reverse(all(leave));

        reset_bitset();

        for (int it: leave) {
            if (!scc[it]) {
                sccID++;
                dfs2(it);
            }
        }
    }
} Kosaraju;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        cnt[i] = 0;
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    Kosaraju.main();

    for (int i = 1; i <= n; i++) {
        for (int e: G[i]) {
            if (Kosaraju.scc[e] != Kosaraju.scc[i]) {
                cnt[Kosaraju.scc[e]]++;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= Kosaraju.sccID; i++)
        if (!cnt[i])
            ans++;
    cout << max(1, ans) << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}