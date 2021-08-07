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
int dp[1000005];

void pre()
{
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            for (int k = 1; k < 101; k++)
            {
                dp[i + j + k]++;
                dp[i + j * k]++;
                dp[i * j + k]++;
                dp[i * j * k]++;
            }
        }
    }
    // for (int i = 1; i < 100; i++)
    //     cout << dp[i] << endl;
}

void sol()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

signed main()
{
    Koying;
    pre();
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}