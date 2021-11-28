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
#define lowbit(x) x &(-x)
int BIT[MAXN];

void update(int id, int value)
{
    while (id < MAXN)
    {
        BIT[id] += value;
        id += lowbit(id);
    }
}
int query(int id)
{
    int sum = 0;
    while (id)
    {
        sum += BIT[id];
        id -= lowbit(id);
    }
    return sum;
}

void sol()
{
    int n, q;
    while (cin >> n >> q)
    {
        int x[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            update(i, x[i]);
        }
        int k, a, b;
        while (q--)
        {
            cin >> k >> a >> b;
            if (k == 1)
            {
                update(a, b - x[a]);
                x[a] = b;
            }
            else
                cout << query(b) - query(a - 1) << endl;
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