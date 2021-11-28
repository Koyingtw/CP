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
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define DE cerr
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        pr x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i + 1;
        }
        sort(x, x + n);
        int tmp[n];
        for (int i = 0; i < n; i++)
            tmp[i] = x[i].F;
        int ans = 0;
        bool yes = 0;
        for (int i = 0; i < n - 3 && !yes; i++)
        {
            for (int j = i + 1; j < n - 2 && !yes; j++)
            {
                if (x[i].F + x[j].F >= k || x[i].F + x[j].F + x[n - 1].F + x[n - 2].F < k)
                    break;
                for (int o = j + 1; o < n - 1 && !yes; o++)
                {
                    if (x[i].F + x[j].F + x[o].F >= k)
                        break;
                    if (x[i].F + x[j].F + x[o].F + x[n - 1].F < k)
                        continue;
                    int l = lower_bound(tmp + o + 1, tmp + n, k - x[i].F - x[j].F - x[o].F) - tmp; //, r = upper_bound(tmp + j, tmp + n, x[i].F - x[j].F) - tmp - 1;
                    if (l == n || tmp[l] != k - x[i].F - x[j].F - x[o].F)
                        continue;
                    set<int> s;
                    s.insert(x[i].S);
                    s.insert(x[j].S);
                    s.insert(x[l].S);
                    s.insert(x[o].S);
                    if (s.size() == 4)
                    {
                        for (int it : s)
                            cout << it << " ";
                        cout << endl;

                        yes = 1;
                    }
                }
            }
        }
        if (!yes)
            cout << "IMPOSSIBLE" << endl;
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