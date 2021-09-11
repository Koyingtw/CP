#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define N 500005
int a[N];
int seg[N * 4];
int tag[N * 4];
struct segtree
{
    void init(int n)
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            seg[i] = 0;
            tag[i] = 0;
        }
    }
    void push(int id, int l, int r)
    {
        seg[id] += tag[id];
        tag[id * 2] += tag[id];
        tag[id * 2 + 1] += tag[id];
        tag[id = 0];
    }

    void update(int id, int val, int l, int r, int ql, int qr)
    {
        push(id, l, r);
        if (ql > r || qr < l)
            return;
        if(ql <= l && qr >= r
        {
            seg[id] += val;
            tag[id] += val;
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, val, l, m, ql, qr);
        update(id * 2 + 1, m + 1, r, ql, qr);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    int query(int id, int l, int r, int ql, int qr)
    {
        push(id, l, r);
        if (qr < l || qr < l)
            return 0;
        if (ql <= l && qr >= r)
            return seg[id];
        int m = (l + r) / 2;
        return query(id, l, m, ql, qr) + query(id, m + 1, r, ql, qr);
    }
};

void sol()
{
    int n, q;
    while (cin >> n)
    {
        segtree st;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        st.build(1, 1, n);
        cin >> q;
        while (q--)
        {
            int v;
            cin >> v;
            if (v == 1)
            {
                int x, y, k;
                cin >> x >> y >> k;
                st.update(1, k, 1, n, x, y);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                cout << st.query(1, 1, n, x, y) << endl;
            }
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