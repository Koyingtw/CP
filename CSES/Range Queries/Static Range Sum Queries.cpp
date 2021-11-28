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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, q;
    while (cin >> n >> q)
    {
        int x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            if (i)
                x[i] += x[i - 1];
        }
        int l, r;
        while (q--)
        {
            cin >> l >> r;
            if (l != 1)
                cout << x[r - 1] - x[l - 2] << endl;
            else
                cout << x[r - 1] << endl;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    // while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}