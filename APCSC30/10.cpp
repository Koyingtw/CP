#pragma region
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
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
#define endl "\n"
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n], y[n], tmp[n], ans = 0;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        cin >> y[0];
        tmp[0] = x[0] * y[0];
        for (int i = 1; i < n; i++)
        {
            cin >> y[i];
            tmp[i] = x[i] * y[i];
            tmp[i] += tmp[i - 1];
        }

        ans = tmp[n - 1];
        for (int i = 0; i < n; i++)
        {
            int maxrange = min(i, n - i - 1), now = x[i] * y[i];
            for (int j = 1; j <= maxrange; j++)
            {
                int l = i - j, r = i + j;
                now += x[l] * y[r] + x[r] * y[l];
                int sum = now;
                sum += tmp[n - 1] - tmp[r];
                if (l)
                    sum += tmp[l - 1];
                ans = max(ans, sum);
            }
            maxrange = min(i + 1, n - i - 1), now = 0;
            for (int j = 1; j <= maxrange; j++)
            {
                int l = i - j + 1, r = i + j;
                now += x[l] * y[r] + x[r] * y[l];
                int sum = now;
                sum += tmp[n - 1] - tmp[r];
                if (l)
                    sum += tmp[l - 1];
                ans = max(ans, sum);
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