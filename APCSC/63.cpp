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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int n, m;
void sol()
{
    while (cin >> n >> m)
    {
        int x[n], y[n], sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            sum += x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
            y[i] = x[i] - y[i];
        }
        sort(y, y + n);
        for (int i = 0; i < n; i++)
        {
            if (sum - y[i] >= m)
            {
                sum -= y[i];
                ans++;
            }
            else
                break;
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