#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

using namespace std;

#define MAXN 200005
int n, q;
int x[MAXN];

struct Seg_Tree {
    struct Node {
        int sum, tag;
        Node(): sum(0), tag(0) {}

        void update(int l, int r, int val) {
            sum += (r - l + 1) * val;
            tag += val;
            // if (l == r && r == 3)
            // cout << "upd:" << val << ' ' << sum << endl;
        }
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        int tag = arr[i].tag;
        arr[i].tag = 0;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        arr[i * 2].update(l, mid, tag);
        arr[i * 2 + 1].update(mid + 1, r, tag);
    }

    

    void build(int i, int l, int r) {
        if (l == r) {
            arr[i].sum = x[l];
            arr[i].tag = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
        // cout << l << ' ' << r << ' ' << arr[i].sum << endl;
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) {
            // cout << l << ' ' << r << ' ' << arr[i].sum << endl;
            return;
        }
        if (ql <= l && r <= qr) {
            arr[i].update(l, r, val);
            // cout << "val: " << val << endl;
            return;
        }

        int mid = (l + r) / 2;
        push(i, l, r);
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
        // cout << l << ' ' << r << ' ' << arr[i].sum << ' ' << arr[i * 2].sum << ' ' << arr[i * 2 + 1].sum << endl;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return arr[i].sum;
        push(i, l, r);
        int mid = (l + r) / 2;
        int q1 = query(i * 2, l, mid, ql, qr);
        int q2 = query(i * 2 + 1, mid + 1, r, ql, qr);
        return q1 + q2;
    }
} seg;


void sol() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)   
        cin >> x[i];

    seg.build(1, 1, n);
    
    // for (int i = 1; i <= 5; i++)
    //     cout << seg.arr[i].sum << endl;

    int op, l, r, val;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> val;
            seg.update(1, 1, n, l, r, val);
        }
        else {
            cin >> l >> r;
            cout << seg.query(1, 1, n, l, r) << endl;
        }
    }
}

signed main() {
    Koying;
    sol();
}