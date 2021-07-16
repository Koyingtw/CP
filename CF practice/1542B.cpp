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
    int x, a, b;
    cin >> x >> a >> b;
    int tmp = 1;
    bool yes = 0;
    while (tmp <= x)
    {
        if ((x - tmp) % b == 0)
        {
            yes = 1;
            break;
        }
        if (a == 1)
            break;
        tmp *= a;
    }
    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}