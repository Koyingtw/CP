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
#define MAXN 400005
#define MAXM 1000005 
int n, m;
int c[MAXN];
vector<int> G[MAXN];
int tt, in[MAXN], out[MAXN];
vector<int> node(1);

struct Segment_Tree {
    struct Node {
        int mask, tag;

        Node operator +(Node a) {
            a.mask |= mask;
            return a;
        }

        void update(Node a) {
            mask = tag = a.tag;
        }

        Node() {
            mask = 0;
            tag = -1;
        }
    };


    Node arr[MAXN << 3];

    void push(int i, int l, int r) {
        if (arr[i].tag == -1)
            return;
        if (l != r) {
            arr[i * 2].update(arr[i]);
            arr[i * 2 + 1].update(arr[i]);
        }
        arr[i].tag = -1;
    }

    void build(int i, int l, int r) {
        arr[i].tag = -1;
        if (l == r) {
            arr[i].mask = (1ll << c[node[l]]);
            return;
        }

        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i].mask = arr[i * 2].mask | arr[i * 2 + 1].mask;
    }

    void update(int i, int l, int r, int ql, int qr, int col) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].mask = (1ll << col);
            arr[i].tag = (1ll << col);
            return;
        }
        int mid = (l + r) / 2;
        push(i, l, r);
        update(i * 2, l, mid, ql, qr, col);
        update(i * 2 + 1, mid + 1, r, ql, qr, col);
        arr[i].mask = (arr[i * 2] + arr[i * 2 + 1]).mask;
        arr[i].tag = -1;
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return Node();
        }
        if (ql <= l && r <= qr)
            return arr[i];
        int mid = (l + r) / 2;
        push(i, l, r);
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} SegT;

struct Euler_Tour {
    void dfs(int i) {
        in[i] = ++tt;
        node.pb(i);

        for (int e: G[i]) if (!in[e]) {
            dfs(e);
        }
        out[i] = ++tt;
        node.pb(i);
    }
} ET;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    ET.dfs(1);
    SegT.build(1, 1, tt);

    int op, v, x;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> v >> x;
            SegT.update(1, 1, tt, in[v], out[v], x);
        }
        else {
            cin >> v;
            auto res = SegT.query(1, 1, tt, in[v], out[v]);
            cout << __builtin_popcountll(res.mask) << endl;
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