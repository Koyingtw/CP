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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
const int P = 1e9 + 7;
void sol()
{
    int n;
    while (cin >> n)
    {
        int sum = n * (n + 1) / 2;
        if (sum % 2)
        {
            cout << 0 << endl;
            continue;
        }
        int dp[sum / 2 + 1];
        MEM(dp, 0);
        dp[0] = 1;
        int x[n];
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum / 2; j >= i; j--)
            {
                dp[j] += dp[j - i];
                dp[j] %= P;
            }
        }

        int ans = dp[sum / 2];
        ans *= 500000004;
        ans %= P;
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