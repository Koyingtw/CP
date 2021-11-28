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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
int seg[MAXN * 4];
int a[MAXN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid), build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] xor seg[id * 2 + 1];
}

int query(int id, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[id];
    int mid = (l + r) / 2;
    int a, b;
    if (qr <= mid)
        return query(id * 2, l, mid, ql, qr);
    if (ql >= mid + 1)
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    return query(id * 2, l, mid, ql, qr) xor query(id * 2 + 1, mid + 1, r, ql, qr);
}
void sol()
{
    int n, q;
    while (cin >> n >> q)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        int a, b;
        while (q--)
        {
            cin >> a >> b;
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