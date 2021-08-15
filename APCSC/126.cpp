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
        int x[n], pre[n], dp[n][3];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            MEM(dp[i], 0);
        }
        pre[0] = x[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + x[i];
        dp[0][0] = x[0];
        dp[0][2] = -x[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + x[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) - x[i];
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