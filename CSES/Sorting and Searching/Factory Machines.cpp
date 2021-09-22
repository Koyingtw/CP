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

void sol()
{
    int n, t;
    while (cin >> n >> t)
    {
        int x[n], mn = INF;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            mn = min(mn, x[i]);
        }
        int l = 1, r = t * mn, m;
        while (l < r)
        {
            int cnt = 0;
            m = l + (r - l) / 2;
            for (int i = 0; i < n; i++)
            {
                cnt += m / x[i];
            }
            if (cnt < t)
                l = m + 1;
            else
                r = m;
        }
        cout << r << endl;
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