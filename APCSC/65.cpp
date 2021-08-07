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

bool cmp(pr a, pr b) { return a.F > b.F; }

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int ans = 0;
        pr x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i].F;
        for (int i = 0; i < n; i++)
            cin >> x[i].S;
        sort(x, x + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (m == 0)
                break;
            if (m / x[i].F > x[i].S)
            {
                m -= x[i].F * x[i].S;
                ans += x[i].S;
            }
            else
            {
                ans += m / x[i].F;
                m %= x[i].F;
            }
        }
        cout << ans << endl;
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