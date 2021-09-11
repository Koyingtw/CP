#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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
int x[1000005], line[1000005];
int dp[1000005][20];

void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        int ans = 1;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        int it = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[x[i]]++;
            while (m.size() != (i - it + 1))
            {
                m[x[it]]--;
                if (m[x[it]] == 0)
                    m.erase(x[it]);
                it++;
            }
            line[i] = it;
        }
        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][0] = max(dp[i][0], i - line[i] + 1);
            ans = max(ans, dp[i][0]);
            for (int j = 1; j < k; j++)
            {
                if (line[i] == 0)
                {
                    dp[i][j] = i + 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = max(dp[i - 1][j], dp[line[i] - 1][j - 1] + i - line[i] + 1);
                ans = max(ans, dp[i][j]);
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
    {
        sol();
        END
    }
    return 0;
}