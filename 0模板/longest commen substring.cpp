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
const int INF = 0x3f3f3f3f;
using namespace std;
/******************************************************************************/

void sol()
{
    string a, b;
    while (cin >> a >> b)
    {
        int dp[a.size() + 1][b.size() + 1];
        int ans = 0;
        MEM(dp[0], 0);
        fr(i, 0, a.size())
        {
            MEM(dp[i + 1], 0);
            fr(j, 0, b.size())
            {
                if (a[i] == b[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                    dp[i + 1][j + 1] = 0;
                ans = max(dp[i + 1][j + 1], ans);
            }
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
        sol();
    return 0;
}