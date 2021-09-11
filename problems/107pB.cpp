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
    double x, y, r;
    while (cin >> x >> y >> r)
    {
        const double sq3 = r / 2.0 * sqrt(3);
        if (x < 0 || y < 0 || x > 1000 || y > 1000)
        {
            cout << 0 << endl;
            continue;
        }

        if ((int)(x / (r * 1.5)) % 2 == 0)
        {
            while (x >= r * 1.5)
            {
                x -= r * 1.5;
            }
            while (y >= sq3 * 2)
            {
                y -= sq3 * 2;
            }
        }
        else
        {
            while (x >= r * 1.5)
            {
                x -= r * 1.5;
            }

            y += sq3;
            while (y >= sq3 * 2)
            {
                y -= sq3 * 2;
            }
        }
        pair<double, double> tmp = {x, y};
        int ans = 0;
        while (tmp.F <= 1000 && tmp.S <= 1000)
        {
            int s = tmp.S;
            while (s <= 1000)
            {
                ans++;
                s += sq3 * 2;
            }
            tmp.F += (r * 1.5);
            tmp.S += sq3;
            while (tmp.S >= sq3 * 2)
            {
                tmp.S -= sq3 * 2;
            }
        }
        cout << ans << endl;
    }
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