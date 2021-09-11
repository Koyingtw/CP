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

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n], t[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        int tmp = t[0];
        for (int i = 1; i < n; i++)
        {
            t[i] = min(t[i], t[i - 1] + x[i - 1]);
        }
        t[0] = min(t[0], t[n - 1] + x[n - 1]);
        cout << t[0] << endl;
        for (int i = 1; i < n; i++)
        {
            t[i] = min(t[i], t[i - 1] + x[i - 1]);
            cout << t[i] << endl;
        }
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