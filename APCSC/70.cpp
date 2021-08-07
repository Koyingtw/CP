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

bool cmp(pr a, pr b)
{
    if (a.F != b.F)
        return a.F < b.F;
    else
        return a.S > b.S;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F >> x[i].S;
        }
        sort(x, x + n, cmp);
        int ans = 1, tmp = x[0].S, mx = 0;
        bool yes = 1;
        for (int i = 1; i < n; i++)
        {
            if (x[i].F <= tmp + 1 && x[i].S > tmp + 1)
            {
                mx = max(mx, x[i].S);
                continue;
            }
            if((x[i].F <= tmp + 1 && x[i].S <= tmp + 1) continue;
            if (x[i].F > tmp + 1)
            {
                if (mx == 0)
                    yes = 0;
                tmp = mx;
                ans++;
                mx = 0;
                if (x[i].F <= tmp + 1 && x[i].S > tmp + 1)
                {
                    mx = max(mx, x[i].S);
                }
            }
        }
        if (mx)
        {
            tmp = mx;
            ans++;
            mx = 0;
        }
        else
            yes = 0;
        if (yes)
            cout << ans << endl;
        else
            cout << -1 << endl;
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
