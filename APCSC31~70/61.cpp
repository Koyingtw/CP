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

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n], ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int mx = 0, a;
            for (int j = 0; j < m; j++)
            {
                cin >> a;
                mx = max(a, mx);
            }
            x[i] = mx;
            sum += mx;
        }
        bool yes = 0;
        cout << sum << endl;
        for (int i = 0; i < n; i++)
        {
            if (sum % x[i] == 0)
            {
                cout << x[i] << " ";
                yes = 1;
            }
        }
        if (!yes)
            cout << -1 << endl;
        else
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
        END
    }
    return 0;
}