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

int dp[505][3005];
int p = 998244353;
void pre()
{
    int n = 505, m = 3005;
    for (int i = 0; i < n; i++)
        MEM(dp, 0);
    dp[0][0] = 1;
    for (int i = 0; i < 6; i++)
    {
        dp[0][i + 1] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k < 7; k++)
            {
                if (j + k <= m)
                    dp[i][j + k] += dp[i - 1][j];
            }
            dp[i][j] %= p;
        }
    }
}
void sol()
{
    int n, m;
    cin >> n >> m;
    {
        cout << dp[n - 1][m] << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    pre();
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}