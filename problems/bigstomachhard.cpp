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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
const int P = 1e9 + 7;
struct Node
{
    int sum, mn, id;
};
int y[100005], h[100005], pre[100005];
Node seg[400005];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = {y[l - 1], h[l - 1], l};
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = (seg[id * 2].mn <= seg[id * 2 + 1].mn ? seg[id * 2] : seg[id * 2 + 1]);
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
    //cout << l << " " << r << " " << seg[id].F << endl;
}

Node query(int id, int l, int r, int ql, int qr)
{
    if (ql <= l && qr >= r)
        return seg[id];
    int m = (l + r) >> 1;
    if (qr <= m)
        return query(id * 2, l, m, ql, qr);
    if (ql > m)
        return query(id * 2 + 1, m + 1, r, ql, qr);
    Node left = query(id * 2, l, m, ql, qr), right = query(id * 2 + 1, m + 1, r, ql, qr), rtn;
    rtn.sum = (left.sum + right.sum);
    rtn.mn = min(left.mn, right.mn);
    rtn.id = (left.mn <= right.mn ? left.id : right.id);
    return rtn;
}

void update(int id, int l, int r, int tar, int val)
{
    if (l == r)
    {
        y[l - 1] += val;
        h[l - 1] = sqrt(y[l - 1]);
        seg[id].mn = h[l - 1];
        seg[id].sum = y[l - 1];
        //seg[id].F += val;
        return;
    }
    int m = l + (r - l) / 2;
    if (tar <= m)
        update(id * 2, l, m, tar, val);
    else
        update(id * 2 + 1, m + 1, r, tar, val);
    seg[id] = (seg[id * 2].mn <= seg[id * 2 + 1].mn ? seg[id * 2] : seg[id * 2 + 1]);
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}

void sol()
{
    int n, q;
    while (cin >> n >> q)
    {
        pre[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
            h[i] = sqrt(y[i]);
            pre[i + 1] = pre[i] + y[i];
            //cout << h[i] << endl;
        }
        build(1, 1, n);
        //cout << query(1, 1, n, 1, 4).mn << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << query(1, 1, n, 1, i).id << endl;
        // }
        while (q--)
        {
            int k, l, r = n;
            cin >> k;
            l = k;

            if (h[k - 1] == 0)
            {
                cout << 0 << " " << 0 << endl;
                continue;
            }

            int m = (l + r) >> 1, range;
            int ans = k;
            int tar = INF;
            while (l <= r)
            {
                m = (l + r) >> 1;
                range = m - k + 1;
                Node Q = query(1, 1, n, k, m);
                pr mn = {Q.mn, Q.id};
                if (mn.F < range)
                    r = m - 1;
                else
                {
                    ans = m;
                    tar = mn.S;
                    l = m + 1;
                }
            }
            cout << ans - k + 1 << " " << query(1, 1, n, k, ans).sum << endl;
            update(1, 1, n, query(1, 1, n, k, ans).id, ans - k + 1);
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