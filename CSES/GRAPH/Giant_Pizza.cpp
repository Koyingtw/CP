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

int rev(int i) {
    return (i + m) % (m * 2);
}

struct Tarjan {
    int tt, sccId;
    int dep[MAXN], low[MAXN], scc[MAXN];
    int opp[MAXN];
    bitset<MAXN> inSt;
    stack<int> st;

    void dfs(int i, int pa) {
        dep[i] = low[i] = ++tt;
        st.push(i);
        inSt[i] = true;

        for (int e: G[i]) {
            if (!dep[e]) {
                dfs(e, i);
                cmin(low[i], low[e]);
            }
            else if (inSt[e]) {
                cmin(low[i], dep[e]);
            }
        }

        if (low[i] == dep[i]) {
            int p;
            sccId++;
            do {
                p = st.top();
                st.pop();
                inSt[p] = false;
                scc[p] = sccId;
            } while (p != i);
        }
    }

    void main() {
        for (int i = 0; i < 2 * m; i++) {
            if (!dep[i])
                dfs(i, i);
        }
    }

    bool check() {
        for (int i = 0; i < m; i++) {
            if (scc[i] == scc[rev(i)])
                return false;
            opp[scc[i]] = scc[rev(i)];
            opp[scc[rev(i)]] = scc[i];
        }
        return true;
    }
} Tarjan;

struct Solver {
    vector<int> G2[MAXN];
    int in[MAXN];
    int ans[MAXN];

    void build() {
        for (int i = 0; i < 2 * m; i++) {
            for (int e: G[i]) if (Tarjan.scc[i] != Tarjan.scc[e]) {
                G2[Tarjan.scc[e]].pb(Tarjan.scc[i]);
                in[Tarjan.scc[i]]++;
            }
        }
    }

    void topo() {
        queue<int> q;
        for (int i = 1; i <= Tarjan.sccId; i++) {
            if (!in[i])
                q.push(i);
        }

        while (q.size()) {
            auto now = q.front();
            q.pop();

            if (!ans[now]) {
                ans[now] = 1;
                ans[Tarjan.opp[now]] = 2;
            }

            for (int e: G2[now]) {
                in[e]--;
                if (!in[e])
                    q.push(e);
            }
        }

        for (int i = 0; i < m; i++)
            cout << (ans[Tarjan.scc[i]] == 1 ? "+ " : "- ");

        cout << endl;
    }
} Solver;

void sol() {
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        char c1, c2;
        int a1, a2;
        cin >> c1 >> a1 >> c2 >> a2;
        a1--, a2--;
        if (c1 == '-')
            a1 += m;
        if (c2 == '-')
            a2 += m;

        G[rev(a1)].pb(a2);
        G[rev(a2)].pb(a1);
    }

    Tarjan.main();
    if (!Tarjan.check()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    Solver.build();
    Solver.topo();
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