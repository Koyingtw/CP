#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 500005
int n, m;
int g[MAXN];

struct Segment_Tree {
    struct Node {
        int lcol, rcol, ans, tag;

        Node(): lcol(0), rcol(0), ans(0), tag(-1) {} // tag = -1: not all

        void update(int val) {
            lcol = rcol = val;
            tag = val;
            ans = 0;
        }
    } arr[MAXN << 2];

    void push(int i) {
        int tag = arr[i].tag;
        if (tag < 0)
            return;

        arr[i * 2].update(tag);
        arr[i * 2 + 1].update(tag);
        arr[i].tag = -1;
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val);
            return;
        }

        int mid = (l + r) / 2;
        push(i);
        // if (qr <= mid) {
        //     update(i * 2, l, mid, ql, qr, val);
        // }
        // if (ql > mid)
        //     update(i * 2 + 1, mid + 1, r, ql, qr, val);

        if (ql <= l)
            arr[i].lcol = val;
        if (qr >= r)
            arr[i].rcol = val;

        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].ans = arr[i * 2].ans + arr[i * 2 + 1].ans + g[mid] * (arr[i * 2].rcol != arr[i * 2 + 1].lcol &&
                                                                     arr[i * 2].rcol * arr[i * 2 + 1].lcol != 0);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return arr[i].ans;
        int mid = (l + r) / 2;

        push(i);

        if (qr <= mid)
            return query(i * 2, l, mid, ql, qr);
        if (ql > mid)
            return query(i * 2 + 1, mid + 1, r, ql, qr);

        int q1 = query(i * 2, l, mid, ql, qr);
        int q2 = query(i * 2 + 1, mid + 1, r, ql, qr);

        return q1 + q2 + g[mid] * (arr[i * 2].rcol != arr[i * 2 + 1].lcol &&
                                   arr[i * 2].rcol * arr[i * 2 + 1].lcol != 0);
    }
} seg;

void sol() {
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        cin >> g[i];

    int op, l, r, x, a, b;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            seg.update(1, 1, n, l, r, x);
            // cout << "debug: " << seg.arr[4].lcol << ' ' << seg.arr[4].rcol << endl;
        }
        else {
            cin >> a >> b;
            int qq = seg.query(1, 1, n, a, b);
            cout << qq << '\n';
        }
    }
}

/*
5 8
8 7 6 3
2 1 4
1 1 3 1 // 1 1 1 0 0
1 2 2 2 // 1 2 1 0 0
2 1 4
1 4 5 1
2 2 5
1 4 4 3
2 1 5

1.
[1, 5]
2.      3.
[1, 3] [4, 5]
4.
[1, 2] [3, 3] [4, 4] [5, 5]
*/

signed main() {
    Koying;
    sol();
    return 0;
}