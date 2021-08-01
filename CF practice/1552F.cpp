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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    int p = 998244353;
    while (cin >> n)
    {
        int x[n], y[n], b[n], nxt[n];
        int dp[n];
        MEM(dp, 127);
        fr(i, 0, n)
        {
            cin >> x[i];
            cin >> y[i];
            cin >> b[i];
            if (i == 0)
                nxt[i] = 0;
            else
            {
                int find = upper_bound(x, x + i, y[i]) - x;
                nxt[i] = find;
            }
            if (nxt[i] == i)
            {
                dp[i] = x[i] - y[i];
            }
        }
        int ans = x[n - 1] + 1;
        int sum[n];
        sum[0] = dp[0];
        fr(i, 0, n)
        {
            if (nxt[i] != i)
            {
                dp[i] = x[i] - y[i];
                if (nxt[i])
                    dp[i] += sum[i - 1] - sum[nxt[i] - 1];
                else
                    dp[i] += sum[i - 1];
            }
            dp[i] %= p;
            if (i)
                sum[i] = sum[i - 1] + dp[i];
        }
        // 1 1 4 13
        // sum =
        fr(i, 0, n)
        {
            if (b[i] != 0)
                ans += dp[i];
        }
        DB(ans % p);
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