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
int y[100005], h[100005], pre[100005];
pr seg[400005];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = {h[l - 1], l - 1};
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = (seg[id * 2].F <= seg[id * 2 + 1].F ? seg[id * 2] : seg[id * 2 + 1]);
    //cout << l << " " << r << " " << seg[id].F << endl;
}

pr query(int id, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
        return seg[id];
    if (ql <= l && qr >= r)
        return seg[id];
    int m = (l + r) >> 1;
    if (qr <= m)
        return query(id * 2, l, m, ql, qr);
    if (ql > m)
        return query(id * 2 + 1, m + 1, r, ql, qr);
    pr left = query(id * 2, l, m, ql, qr), right = query(id * 2 + 1, m + 1, r, ql, qr);
    return (left.F <= right.F ? left : right);
}

void update(int id, int l, int r, int tar, int val)
{
    if (l == r)
    {
        seg[id].F += val;
        return;
    }
    int m = (l + r) >> 1;
    if (tar <= m)
        update(id * 2, l, m, tar, val);
    else
        update(id * 2 + 1, m + 1, r, tar, val);
    seg[id] = (seg[id * 2].F <= seg[id * 2 + 1].F ? seg[id * 2] : seg[id * 2 + 1]);
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
            while (l <= r)
            {
                m = (l + r) >> 1;
                range = m - k + 1;
                int mn = query(1, 1, n, k, m).F;
                if (mn < range)
                    r = m - 1;
                else
                {
                    ans = m;
                    l = m + 1;
                }
            }
            cout << ans - k + 1 << " " << pre[ans] - pre[k - 1] << endl;
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