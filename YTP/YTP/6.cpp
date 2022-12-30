
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
int dp[3005][3005];
void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        int x[n + 2];
        MEM(dp, -63);
        //cout << dp[0][0] << endl;
        dp[0][0] = 0;
        dp[1][0] = x[1];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i + 1];
            dp[i + 1][0] = dp[i][0] + x[i + 1];
        }
        x[n + 1] = 0;
        int ans = dp[n][0];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i + 1][j] = max(dp[i][j] + x[i + 1], dp[i - 1][j - 1] + x[i + 1]);
            }
        }
        for (int i = 1; i <= k; i++)
            ans = max(ans, dp[n + 1][i]);
        for (int i = 1; i <= k; i++)
            ans = max(ans, dp[n][i]);
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
    }
    return 0;
}