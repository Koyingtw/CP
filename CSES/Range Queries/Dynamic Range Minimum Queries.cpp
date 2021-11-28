#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 2000000005;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
int seg[MAXN * 4];
int a[MAXN];

int pull(int l, int r)
{
    return min(seg[l], seg[r]);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = pull(id * 2, id * 2 + 1);
    // cout << seg[id] << endl;
}

int query(int id, int l, int r, int ql, int qr)
{
    if (l == r)
        return seg[id];
    int mid = (l + r) / 2;
    int ans = INF;
    if (ql <= mid)
        ans = min(query(id * 2, l, mid, ql, qr), ans);
    if (qr >= mid + 1)
        ans = min(ans, query(id * 2 + 1, mid + 1, r, ql, qr));
    return ans;
}

void update(int id, int l, int r, int tar, int val)
{
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (tar <= mid)
        update(id * 2, l, mid, tar, val);
    else
        update(id * 2 + 1, mid + 1, r, tar, val);

    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
    // cout << l << " " << r << " " << seg[id] << endl;
}

void sol()
{
    int n, q;
    while (cin >> n >> q)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            update(1, 1, n, i, a[i]);
        }

        int k, a, b;
        while (q--)
        {
            cin >> k >> a >> b;
            if (k == 1)
                update(1, 1, n, a, b);
            else
                cout << query(1, 1, n, a, b) << endl;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    // while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}