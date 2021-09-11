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
int ans[1005];
short dp[102];
void pree()
{
    int tmp = 1, i = 1;
    while (tmp <= 1000)
    {
        if (i % 3 != 0 && i % 10 != 3)
        {
            dp[tmp++] = i;
        }
        i++;
    }
}
void pre()
{
    int cnt = 1;
    for (int i = 0; i < 1005; i++)
    {
        while (cnt % 10 == 3 || cnt % 3 == 0)
            cnt++;
        ans[i] = cnt;
        cnt++;
    }
    for (int i = 0; i < 1005; i++)
    {
        cout << i + 1 << ": " << dp[i + 1] << endl;
    }
}
void sol()
{
    int n;
    cin >> n;
    cout << ans[n - 1] << endl;
}

signed main()
{
    Koying;
    int t = 1;
    pree();
    pre();
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}