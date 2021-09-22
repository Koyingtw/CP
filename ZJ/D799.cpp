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
#define MAXN 500005
int n, q;
int x[MAXN], seg[MAXN * 4], tag[MAXN * 4];

void init()
{
    MEM(seg, 0);
    MEM(tag, 0);
    return;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = x[l - 1];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void push(int id, int l, int r)
{
    seg[id] += tag[id] * (r - l + 1);
    tag[id * 2] += tag[id];
    tag[id * 2 + 1] += tag[id];
    tag[id] = 0;
}

int query(int id, int l, int r, int ql, int qr)
{
    push(id, l, r);
    //cout << seg[id] << endl;
    if (r < ql || qr < l)
        return 0;
    int m = (l + r) >> 1;
    if (ql <= l && qr >= r)
        return seg[id];
    return query(id * 2, l, m, ql, qr) + query(id * 2 + 1, m + 1, r, ql, qr);
}
void update(int id, int l, int r, int ql, int qr, int val)
{
    push(id, l, r);
    if (r < ql || qr < l)
        return;
    if (ql <= l && qr >= r)
    {
        //seg[id] += val;
        tag[id] += val;
        //cout << l << " " << r << " " << seg[id] << " " << tag[id] << endl;
        return;
    }
    int m = (l + r) >> 1;

    update(id * 2, l, m, ql, qr, val);
    update(id * 2 + 1, m + 1, r, ql, qr, val);

    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void sol()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> x[i];
        init();
        build(1, 1, n);

        cin >> q;
        while (q--)
        {
            int v, a, b, k;
            cin >> v;
            if (v == 1)
            {
                cin >> a >> b >> k;
                update(1, 1, n, a, b, k);
                cout << seg[1] << endl;
            }
            else
            {
                cin >> a >> b;
                cout << query(1, 1, n, a, b) << endl;
                cout << seg[1] << endl;
            }
        }
        //cout << seg[1] << endl;
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