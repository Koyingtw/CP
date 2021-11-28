#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define N 200005

int a[N];
int seg[N * 4];

int pull(int x, int y)
{
    return seg[x] + seg[y];
}

void build(int id, int l, int r)
{
    if (r == l)
    {
        seg[id] = a[l - 1];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = pull(id * 2, id * 2 + 1);
}

int query(int id, int l, int r, int ql, int qr) //l, r:當前節點的區間 ql, qr:欲查詢區間
{
    if (qr < l || ql > r)
        return 0;
    if (ql <= l && r <= qr)
        return seg[id];

    int m = (l + r) / 2;
    if (r <= m)
        return query(id, l, m, ql, qr);
    if (l > m)
        return query(id * 2 + 1, m + 1, r, ql, qr);
    return query(id * 2, l, m, ql, qr) + query(id * 2 + 1, m + 1, r, ql, qr);
}

void update(int id, int l, int r, int i, int val)
{
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int m = (l + r) / 2;
    if (id < m)
        update(id, l, m, i, val);
    else
        update(id, m + 1, r, i, val);
    seg[id] = pull(id * 2, id * 2 + 1);
}

void sol()
{
    int n, q;
    while (cin >> n)
    {
        //segtree t1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        build(1, 1, n);
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}