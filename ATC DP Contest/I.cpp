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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        long double x[n], pre[n], ans = 0.0;
        int mx = n / 2;
        long double dp[n][n / 2 + 1] = {0.0};
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            pre[i] = x[i];
            if (i)
                pre[i] *= pre[i - 1];
            for (int j = 0; j <= mx; j++)
                dp[i][j] = 0.0;
            dp[i][0] = pre[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = min(i + 1, mx); j >= 1; j--)
            {
                if (i)
                    dp[i][j] = dp[i - 1][j - 1] * (1.0 - x[i]) + dp[i - 1][j] * x[i];
                else
                    dp[i][j] = (1.0 - x[i]);
            }
        }
        for (int j = 0; j <= mx; j++)
            ans += dp[n - 1][j];
        // for (int i = 0; i < n; i++)
        // {
        //     for (double it : dp[i])
        //         cout << it << " ";
        //     cout << endl;
        // }
        cout << fixed << setprecision(15) << ans << endl;
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