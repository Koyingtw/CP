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
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define DE cerr
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int dp[5005][5005];
void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n + 1], pre[n + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            pre[i] = pre[i - 1] + x[i];
            dp[i][i] = x[i];
        }
        for (int d = 1; d < n; d++) 
        {
            for (int i = 1; i <= n; i++) 
            {
                if (i + d > n)
                    break;
                if(d % 2)
                	dp[i][i + d] = min(pre[i + d] - pre[i - 1] - dp[i + 1][i + d], pre[i + d] - pre[i - 1] - dp[i][i + d - 1]);
                else dp[i][i + d] = max(pre[i + d] - pre[i - 1] - dp[i + 1][i + d], pre[i + d] - pre[i - 1] - dp[i][i + d - 1]);
            }
        }
        cout << dp[2][n] << " " << dp[1][n - 1] << endl;
        cout << max(dp[2][n], dp[1][n - 1]) << endl;
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