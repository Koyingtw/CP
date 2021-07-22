#include <bits/stdc++.h>
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const signed p = 1000000007;
signed dp[105][1000005];
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n];
        fr(i, 0, n)
        {
            cin >> x[i];
            memset(dp[i + 1], 0, sizeof(dp[i]));
        }
        sort(x, x + n);
        dp[0][0] = 1;
        fr(i, 0, m + 1)
        {
            fr(j, 0, n)
            {
                dp[j + 1][i] = dp[j][i];
                int a = i - x[j];
                if (a >= 0)
                {
                    (dp[j + 1][i] += dp[j + 1][a]) %= p;
                }
            }
        }
        int ans = 0;

        cout << dp[n][m] << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}