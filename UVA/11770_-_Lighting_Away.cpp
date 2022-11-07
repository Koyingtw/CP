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
int Case = 0;
vector<int> G[MAXN];

struct tarjan_SCC {
    int dep[MAXN], low[MAXN], scc[MAXN];
    int timestamp = 0, sccID = 0;
    stack<int> st;
    bitset<MAXN> inSt;

    void dfs(int i) {
        dep[i] = low[i] = ++timestamp;
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
        if (dep[i] == low[i]) {
            int point;
            sccID++;
            do {
                point = st.top();
                st.pop();
                inSt[point] = false;
                scc[point] = sccID;
            } while (point != i);
        }
    }

    int main() {
        for (int i = 1; i <= n; i++)
            dep[i] = low[i] = scc[i] = inSt[i] = 0;
        timestamp = sccID = 0;
        while (st.size())
            st.pop();

        for (int i = 1; i <= n; i++)
            if (!dep[i])
                dfs(i);
        return sccID;
    }
} tarjan;


void sol() {
    Case++;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        G[i].clear();
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    int sccCnt = tarjan.main();
    set<int> st;


    for (int i = 1; i <= n; i++) {
        for (int e: G[i]) {
            if (tarjan.scc[i] != tarjan.scc[e])
                st.insert(tarjan.scc[e]);
        }
    }

    cout << "Case " << Case << ": " << max(1, sccCnt - st.size()) << endl;
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