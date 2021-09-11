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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        int ans[n] = {0}, pre[n];
        pr x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i;
        }
        sort(x, x + n);
        pre[0] = x[0].F;
        for (int i = 1; i < n; i++)
        {
            ans[x[i].S] = x[i].F * i - pre[i - 1];
            pre[i] = pre[i - 1] + x[i].F;
        }
        for (int i = 0; i < n; i++)
        {
            ans[x[i].S] -= (pre[n - 1] - pre[i]) - x[i].F * (n - i - 1);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
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