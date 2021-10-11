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
    int n, k;
    while (cin >> n >> k)
    {
        int x[n];
        int l = 1, r = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            r += x[i];
        }

        int m = (l + r) >> 1;
        int ans = r;
        while (l < r)
        {
            int tmp = 0;
            int ouo = 0;
            m = (l + r) >> 1;
            for (int i = 0; i < n; i++)
            {
                if (x[i] > m)
                {
                    tmp = INF;
                    break;
                }
                if (ouo + x[i] > m)
                {
                    tmp++;
                    ouo = x[i];
                }
                else if (ouo + x[i] == m)
                {
                    tmp++;
                    ouo = 0;
                }
                else
                    ouo += x[i];
            }
            if (ouo)
                tmp++;
            if (tmp <= k)
            {
                r = m;
            }
            else
                l = m + 1;
        }
        cout << l << endl;
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