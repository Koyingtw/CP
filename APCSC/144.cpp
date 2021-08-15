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
    int n, m;
    while (cin >> n >> m)
    {
        int x[n][m];
        int dp[n][m];
        for (int i = 0; i < n; i++)
        {
            MEM(dp[i], 0);
            for (int j = 0; j < m; j++)
                cin >> x[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (x[i][j] == -1)
                    continue;

                if (i)
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                if (j)
                    dp[i][j] = max(dp[i][j - 1], dp[i][j]);
                dp[i][j] += x[i][j];
            }
        }
        cout << dp[n - 1][m - 1] << endl;
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