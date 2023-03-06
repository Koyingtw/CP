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
#define lowbit(x) (x &(-x))
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
int n, s, t, w;
vector<int> G[MAXN];
vector<pii> E;

struct Segment_Tree {
    vector<int> arr {0};

    void update(int i, int val) {
        for (; i < arr.size(); i += lowbit(i)) 
            arr[i] += val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += arr[i];
        return res;
    }
} seg;

struct Eular {
    int tt = 0;
    int in[MAXN], out[MAXN], d[MAXN];
    vector<pii> v {{INF, -1}};

    vector<pii> ST[30];

    void dfs(int i, int dep) {
        d[i] = dep;
        in[i] = ++tt;
        seg.arr.pb(dep);
        for (int e: G[i]) {
            if (in[e]) continue;
            dfs(e, dep + 1);
        }
        out[i] = tt;
    }
} Eu;

void sol() {
    cin >> n >> s >> t >> w;
    w += t;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        E.pb({a, b});
    }
    Eu.dfs(s, 0);

    for (int i = seg.arr.size() - 1; i > 0; i--) {
        seg.arr[i] -= seg.arr[(i - lowbit(i))];
    }

    int m = Eu.v.size();

    int op, x, y, z;
    while (w--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            cout << abs(x * seg.query(Eu.in[y])) << endl;
        }
        else {
            cin >> z;
            z--;

            int a = E[z].F;
            int b = E[z].S;
            if (Eu.in[a] < Eu.in[b])
                swap(a, b);
            seg.update(Eu.in[a], -1);
            seg.update(Eu.out[a] + 1, 1);
        }
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