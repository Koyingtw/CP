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
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define DE cerr
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n], pre[n], rep[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        pre[0] = x[0];
        rep[n - 1] = x[n - 1];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + x[i];
        for (int i = n - 2; i >= 0; i--)
            rep[i] = rep[i + 1] + x[i];
        int ans = pre[n - 1];
        for (int i = 0; i < n; i++)
        {
            if ((pre[i] < rep[i] && pre[i] > rep[i] - x[i]))
            {
                ans += pre[i] - (rep[i] - x[i]);
            }
            else if (rep[i] < pre[i] && rep[i] > pre[i] - x[i])
            {
                DE << pre[i] << " " << rep[i] << " " << x[i] << endl;
                ans += rep[i] - (pre[i] - x[i]);
            }
        }
        cout << max(2 * (*max_element(x, x + n)), pre[n - 1]) << endl;
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