#pragma region
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

struct in
{
    int n;
} in;

void sol()
{
    while (cin >> in.n)
    {
        int x[in.n];
        for (int i = 0; i < in.n; i++)
            cin >> x[i];
        int mx = 0;
        for (register int i = 0; i < in.n - 1; i++)
        {
            mx = max(mx, (x[i] + x[i + 1]) * 3);
        }
        for (register int i = 1; i < in.n - 1; i++)
        {
            mx = max(mx, (x[i - 1] + x[i] + x[i + 1]) * 2);
        }
        register int range = 6;
        if (mx % 3 == 0)
        {
            range /= 3;
            mx /= 3;
        }
        if (mx % 2 == 0)
        {
            range /= 2;
            mx /= 2;
        }
        cout << mx << " " << range << endl;
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