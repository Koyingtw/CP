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
    int n, k;
    while (cin >> n >> k)
    {
        int x[n], dp[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int mn = INF;
            for (int j = i - 1; j >= max(1 - 1, i - k); j--)
                mn = min(mn, dp[j] + abs(x[i] - x[j]));
            dp[i] = mn;
        }
        cout << dp[n - 1] << endl;
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