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
int x[200005];
int n, q;
int rmq[20][200005];
void build()
{
    for (int i = 1; (1 << i) <= n; i++)
    {
        int range = (1 << i);
        for (int j = 0; j < n; j++)
        {
            if (j + (range) > n)
                break;
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (range / 2)]);
        }
    }
}
int query(int l, int r)
{
    int range = (r - l) + 1;
    int lg = log2(range);
    int mn = INF;
    mn = min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    return mn;
}
void sol()
{
    while (cin >> n >> q)
    {
        MEM(rmq, 63);
        for (int i = 0; i < n; i++)
            cin >> rmq[0][i];

        build();
        int l, r;
        while (q--)
        {
            cin >> l >> r;
            l--, r--;
            cout << query(l, r) << endl;
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