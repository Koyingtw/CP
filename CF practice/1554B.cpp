#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
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
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y;
    cin >> x >> y;
    int ans = INF;
    if (x + (c - a) <= n)
    {
        ans = min(ans, x - (n - c));
        ans = min(ans, x - a);
    }
    if (y + (d - b) <= m)
    {
        ans = min(ans, y - b);
        ans = min(ans, y - (m - d));
    }
    if (x + (c - a) > n && y + (d - b) > m)
    {
        cout << -1 << endl;
        return;
    }
    if (ans <= 0)
        cout << 0 << endl;
    else
        cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}