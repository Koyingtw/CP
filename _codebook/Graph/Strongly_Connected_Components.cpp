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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];

struct SCC {
    int timestamp = 1;
    int D[MAXN], L[MAXN], cont[MAXN], SCCID = 1;
    stack<int> st;
    bitset<MAXN> inSt;

    void dfs(int i, int fa) {
        D[i] = L[i] = timestamp++;
        st.push(i);
        inSt[i] = true;

        for (int e: G[i]) {
            if (e == fa) {

                // continue;
            }
            if (!D[e]) {
                dfs(e, i);
                cmin(L[i], L[e]);
            }
            else if (inSt[e]) {
                cmin(L[i], D[e]);
            }
        }

        if (D[i] == L[i]) {
            int cur;
            do {
                cur = st.top();
                st.pop();
                inSt[cur] = false;
                cont[cur] = SCCID;
            } while (cur != i);
            SCCID++;
        }
    }
} SCC;

void sol() {
	cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
    }

    for (int i = 0; i < n; i++) {
        if (!SCC.D[i])
            SCC.dfs(i, i);
    }

    // SCC.dfs(0, 0);

    cout << SCC.SCCID - 1 << endl;
    vector<vector<int>> ans(SCC.SCCID);
    for (int i = 0; i < n; i++) {
        // cout << SCC.cont[i] << " ";
        if (SCC.cont[i])
            ans[SCC.cont[i]].pb(i);
    }
    // cout << endl;

    for (int i = SCC.SCCID - 1; i; i--) {
        cout << ans[i].size() << " ";
        for (int it: ans[i])
            cout << it << " ";
        cout << endl;
    }
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