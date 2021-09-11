#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
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
    int n, q;
    while (cin >> n >> q)
    {
        int x[n];
        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            m[x[i]]++;
        }
        while (q--)
        {
            int in;
            cin >> in;
            int a, b, c;
            a = lower_bound(x, x + n, in) - x;
            b = (m[in] > 0 ? m[in] - 1 : 0);
            c = n - (upper_bound(x, x + n, in) - x);
            cout << a << " " << b << " " << c << endl;
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
    }
    return 0;
}