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

int f(int n) { return ((n - 1) % 2); }

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int dp[2][m], l[m], r[m];
        int tmp[m], ans = 0;
        MEM(dp[0], 0);
        MEM(dp[1], 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> tmp[j];
            }
            MEM(l, 0);
            MEM(r, 0);
            if (i)
            {
                l[0] = dp[f(i)][0] + tmp[0];
                r[m - 1] = dp[f(i)][m - 1] + tmp[m - 1];
                for (int j = 1; j < m; j++)
                {
                    l[j] = max(l[j - 1], dp[f(i)][j]) + tmp[j];
                }
                for (int j = m - 2; j >= 0; j--)
                {
                    r[j] = max(r[j + 1], dp[f(i)][j]) + tmp[j];
                }
                for (int j = 0; j < m; j++)
                    dp[i % 2][j] = max(l[j], r[j]);
            }
            else
            {
                l[0] = tmp[0];
                r[m - 1] = tmp[m - 1];
                for (int j = 1; j < m; j++)
                {
                    l[j] = max(l[j - 1], 0) + tmp[j];
                }
                for (int j = m - 2; j >= 0; j--)
                {
                    r[j] = max(r[j + 1], 0) + tmp[j];
                }
                for (int j = 0; j < m; j++)
                    dp[i % 2][j] = max(l[j], r[j]);
            }
        }
        for (int j = 0; j < m; j++)
        {
            ans = max(dp[f(n)][j], ans);
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