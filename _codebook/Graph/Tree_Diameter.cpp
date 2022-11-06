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
vector<pii> G[MAXN];
bitset<MAXN> vis;
int ans = 0;
int pathmid;
int mxchd[MAXN];
int ndchd[MAXN];

int dfs(int i, int dep) {
    vis[i] = true;
    pii mx(dep, dep);
    mxchd[i] = ndchd[i] = -1;

    for (pii e: G[i]) {
        if (vis[e.F])
            continue;
        int tmp = dfs(e.F, dep + e.S);
        // cout << tmp << endl;
        if (tmp > mx.F) {
            mx = {tmp, mx.F};
            ndchd[i] = mxchd[i];
            mxchd[i] = e.F;
        }
        else if (tmp > mx.S) {
            mx.S = tmp;
            ndchd[i] = e.F;
        }
    }   
    if (ans < mx.F + mx.S - 2 * dep) {
        ans = mx.F + mx.S - 2 * dep;
        pathmid = i;
    }
    return mx.F;
}

void sol() {
	cin >> n;

    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    dfs(0, 0);

    cout << ans << ' ';
    deque<int> dq;
    int cur = pathmid;
    while (cur > -1) {
        dq.pb(cur);
        cur = mxchd[cur];
    }
    dq.pop_front();
    cur = pathmid;
    while (cur > -1) {
        dq.push_front(cur);
        cur = ndchd[cur];
    }
    cout << dq.size() << endl;
    for (int it: dq)
        cout << it << " ";
    cout << endl;
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