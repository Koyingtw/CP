#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define lowbit(x) (x & (-x))
#define pb push_back
#define pf push_front
#define MEM(x, n) memset(x, n, sizeof(x))
#define cmax(a, b) (a = max(a, b))
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 100005

int n, m, q;
vector<int> a, b, c, d;

struct SegTree {
    struct Node {
        int sum, pre, suf, ans;

        Node(): sum(0), pre(-INF), suf(-INF), ans(-INF) {}

        Node(int val): sum(val), pre(val), suf(val), ans(val) {}

        Node operator +(Node _a) {
            Node res;
            res.pre = max(pre, sum + _a.pre);
            res.suf = max(_a.suf, _a.sum + suf);
            res.sum = sum + _a.sum;
            res.ans = max(ans, _a.ans);
            cmax(res.ans, suf + _a.pre);
            cmax(res.ans, suf);
            cmax(res.ans, _a.pre);
            return res;
        }
    } arr[MAXN << 2];



    void build(vector<int> &x, int i, int l, int r) {
        if (l == r) {
            arr[i] = Node(x[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(x, i * 2, l, mid);
        build(x, i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int i, int l, int r, int pos, int val) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            arr[i] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        update(i * 2, l, mid, pos, val);
        update(i * 2 + 1, mid + 1, r, pos, val);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return Node(0);
        if (ql <= l && r <= qr)
            return arr[i];
        int mid = (l + r) / 2;
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} Seg[4];

void sol() {
    cin >> n >> m >> q;
    a.resize(n + 1);
    b.resize(m + 1);
    c.resize(n + 1);
    d.resize(m + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = -a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        d[i] = -b[i];
    }
    Seg[0].build(a, 1, 1, n);
    Seg[1].build(b, 1, 1, m);
    Seg[2].build(c, 1, 1, n);
    Seg[3].build(d, 1, 1, m);

    int op, id, val;
    pii ld, rt;
    while (q--) {
        cin >> op;
        if (op <= 2) 
            cin >> id >> val;
        else
            cin >> ld.F >> ld.S >> rt.F >> rt.S;

        if (op == 1) {
            Seg[0].update(1, 1, n, id, val);
            Seg[2].update(1, 1, n, id, -val);
        }
        if (op == 2) {
            Seg[1].update(1, 1, m, id, val);
            Seg[3].update(1, 1, m, id, -val);
        }
        if (op == 3) {
            auto q1 = Seg[0].query(1, 1, n, ld.F, rt.F);
            auto q2 = Seg[1].query(1, 1, m, ld.S, rt.S);
            auto q3 = Seg[2].query(1, 1, n, ld.F, rt.F);
            auto q4 = Seg[3].query(1, 1, m, ld.S, rt.S);
        
            cout << max({q1.ans * q2.ans, q3.ans * q4.ans, 0ll}) << '\n';
        }
    }
}

signed main() {
    Koying
    sol();
    return 0;
}

/*
4 4 7
1 -1 2 -9
3 -4 -2 0
3 1 1 4 4
1 4 -17
3 1 2 4 2
2 2 6
3 1 2 4 2
1 4 1
3 1 1 4 4
*/