#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#define endl "\n"
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        int pre[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i;
            pre[i] = x[i].F;
            if (i)
                pre[i] += pre[i - 1];
        }
        sort(x, x + n);
        int l = 0, r = n - 1;
        int tmp = 0;
        while (l != r)
        {
            if (x[tmp].S <= r && x[tmp].S >= l)
            {
                int left, right;
                if (x[tmp].S == l)
                {
                    l++;
                    continue;
                }
                if (l)
                    left = pre[x[tmp].S - 1] - pre[l - 1];
                else
                    left = pre[x[tmp].S - 1];
                right = pre[r] - pre[x[tmp].S];
                if (left > right)
                    r = x[tmp].S - 1;
                else
                    l = x[tmp].S + 1;
            }
            tmp++;
        }
        if (l)
            cout << pre[l] - pre[l - 1] << endl;
        else
            cout << pre[l] << endl;
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