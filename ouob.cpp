#include <bits/stdc++.h>

using namespace std;;

#define MAXN 200005

#define int long long

int n, m;
int x[MAXN];

struct Seg {
    int arr[MAXN << 2];

    void build(int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i] = x[l];
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int pos, int val, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(pos, val, i * 2, l, mid);
        else
            update(pos, val, i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    int query(int ql, int qr, int i = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr)
            return arr[i];
        if (l > qr || r < ql)
            return 0;
        int mid = (l + r) / 2;
        return query(ql, qr, i * 2, l, mid) + query(ql, qr, i * 2 + 1, mid + 1, r);
    }
} seg;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    seg.build();

    int op, a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 1) {
            seg.update(a, b);
        }
        else
            cout << seg.query(a, b) << endl;
    }
}