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
    int m;
    cin >> m;
    int x[2][m], dp[2][m];
    MEM(dp[0], 0);
    MEM(dp[1], 0);
    fr(i, 0, 2)
    {
        fr(j, 0, m)
        {
            cin >> x[i][j];
            if (j && i == 0)
            {
                dp[i][j] = dp[i][j - 1] + x[i][j];
            }
            if (i == 1)
            {
                if (j == 0)
                    dp[i][j] = x[i][j];
                else if (j != m - 1)
                    dp[i][j] = dp[i][j - 1] + x[i][j];
            }
        }
    }
    int ans = dp[0][m - 1] - dp[0][0];
    fr(i, 1, m)
    {
        ans = min(ans, max(dp[0][m - 1] - dp[0][i], dp[1][i - 1]));
    }
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