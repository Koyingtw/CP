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
int coin[MAXN];
vector<int> G[MAXN];

struct Tarjan {
    int tt, sccId;
    int dep[MAXN], low[MAXN], scc[MAXN], sum[MAXN], in[MAXN], dp[MAXN];
    stack<int> st;
    bitset<MAXN> inSt;
    vector<int> G2[MAXN];

    void dfs(int i) {
        dep[i] = low[i] = ++tt;
        st.push(i);
        inSt[i] = true;
        for (int e: G[i]) {
            if (!dep[e]) {
                dfs(e);
                cmin(low[i], low[e]);
            }
            else if (inSt[e])
                cmin(low[i], dep[e]);
        }

        if (low[i] == dep[i]) {
            int p;
            sccId++;

            do {
                p = st.top();
                inSt[p] = false;
                st.pop();
                scc[p] = sccId;
                sum[sccId] += coin[p];
            } while (p != i);
        }
    }

    void main() {
        for (int i = 1; i <= n; i++) if (!dep[i])
            dfs(i);
        for (int i = 1; i <= n; i++) {
            for (int e: G[i]) if (scc[i] != scc[e]) {
                G2[scc[i]].pb(scc[e]);
                in[scc[e]]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= sccId; i++) if (!in[i])
            q.push(i);
        while (q.size()) {
            auto now = q.front();
            q.pop();

            dp[now] += sum[now];

            for (int e: G2[now]) {
                in[e]--;
                cmax(dp[e], dp[now]);
                if (!in[e])
                    q.push(e);
            }
        }
    }
} Tarjan;


void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    Tarjan.main();
    cout << *max_element(Tarjan.dp + 1, Tarjan.dp + 1 + Tarjan.sccId) << endl;
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