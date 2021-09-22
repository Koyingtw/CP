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
    int n;
    while (cin >> n)
    {
        int x[n][3];
        int dp[n][3];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> x[i][j];
        for (int i = 0; i < n; i++)
            MEM(dp[i], 0);
        for (int i = 0; i < 3; i++)
            dp[0][i] = x[0][i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int mx = 0;
                for (int k = 0; k < 3; k++)
                {
                    if (k == j)
                        continue;
                    mx = max(mx, dp[i - 1][k] + x[i][j]);
                }
                dp[i][j] = mx;
            }
        }
        cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
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