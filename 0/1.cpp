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
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define DE cerr
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 500005
struct Node
{
    int l, r, tag, sum;
    void update(int val) { sum += (r - l + 1) * val, tag += val; }
};
int n, q;
int a[MAXN];
Node seg[MAXN * 4];

void build(int id, int l, int r)
{
    seg[id].l = l, seg[id].r = r;
    if (seg[id].l == seg[id].r)
    {
        seg[id].sum = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(id * 2, l, m), build(id * 2 + 1, m + 1, r);
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}
void pull(int id)
{
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}
void push(int id)
{
    int tag = seg[id].tag;
    seg[id * 2].update(tag), seg[id * 2 + 1].update(tag);
    seg[id].tag = 0;
}
int query(int id, int ql, int qr)
{
    int l = seg[id].l, r = seg[id].r;
    if (ql <= l && r <= qr)
        return seg[id].sum;
    push(id);
    int m = (l + r) / 2, ans = 0;
    if (ql <= m)
        ans += query(id * 2, ql, qr);
    if (qr > m)
        ans += query(id * 2 + 1, ql, qr);
    return ans;
}
void update(int id, int ql, int qr, int val)
{
    int l = seg[id].l, r = seg[id].r;
    if (ql <= l && r <= qr)
        seg[id].update(val);
    else
    {
        push(id);
        int m = (l + r) / 2;
        if (ql <= m)
            update(id * 2, ql, qr, val);
        if (qr > m)
            update(id * 2 + 1, ql, qr, val);
        pull(id);
    }
}

void sol()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        cin >> q;
        int v, a, b, k;
        while (q--)
        {
            cin >> v;
            if (v == 1)
            {
                cin >> a >> b >> k;
                update(1, a, b, k);
            }
            else
            {
                cin >> a >> b;
                cout << query(1, a, b) << endl;
            }
        }
        // for(int i = 1; i < 8; i++)
        // cout << tag[i] << endl;
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
    }
    return 0;
}