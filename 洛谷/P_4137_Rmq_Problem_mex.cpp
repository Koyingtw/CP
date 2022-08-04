#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], ans[MAXN];
tuple<int, int, int> q[MAXN];


struct segment_tree {
    struct Node {
        int mx;


        Node operator + (const Node &_a) {
            Node res;
            res.mx = max(mx, _a.mx);
            return res;
        }
    } seg[MAXN << 2];

    inline void build(const int &i, const int &l, const int &r) {
        if (l == r) {
            seg[i].mx = INF;
            return;
        }
        const int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }

    inline void update(const int &i, const int &l, const int &r, const int &pos, const int &val) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            seg[i].mx = val;
            return;
        }
        const int &mid = (l + r) >> 1;
        update(i << 1, l, mid, pos, val);
        update(i << 1 | 1, mid + 1, r, pos, val);
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }

    inline int query(const int &i, const int &l, const int &r, const int &qr) {
        if (l == r)
            return l;
        if (seg[i << 1].mx > qr)
            return query(i << 1, l, (l + r) >> 1, qr);
        else
            return query(i << 1 | 1, ((l + r) >> 1) + 1, r, qr);
    }
} seg;

void sol() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        q[i] = {l, r, i};
    }
    seg.build(1, 0, 2e5 + 1);

    sort(q, q + m, greater<tuple<int, int, int>>());

    int now = n;
    for (int i = 0; i < m; i++) {
        const auto &[l, r, id] = q[i];
        while (now >= l) {
            seg.update(1, 0, 2e5 + 1, x[now], now);
            now--;
        }
        ans[id] = seg.query(1, 0, 2e5 + 1, r);
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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