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

signed dp[5000005] = {0, 1, 2};
const int p = 1e9 + 7;
void pre()
{
    for (int i = 3; i < 5000005; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= p;
    }
}

void sol()
{
    int n;
    while (cin >> n)
        cout << dp[n] % p << endl;
}

signed main()
{
    Koying;
    pre();
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}