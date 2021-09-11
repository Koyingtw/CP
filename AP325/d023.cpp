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
    int n, m, w;
    while (cin >> n >> m >> w)
    {
        int l = m, r = m + 1;
        int x[n], ans[n];
        MEM(ans, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        int tall = min(x[r], x[l]);
        if (tall >= w)
        {
            for (int i = 0; i < l; i++)
                cout << 0 << " ";
            cout << w << endl;
            for (int i = r; i < n; i++)
                cout << 0 << " ";
            cout << endl;
            break;
        }
        ans[l] = x[l];
        int now = 0;
        int tmp = min(x[r], x[l]);
        while (1)
        {
            if (x[l] < x[r])
            {
                for (int i = l - 1; i >= 0; i--)
                {
                    if (x[i] > x[l])
                    {
                        l = i;
                        break;
                    }
                    if (i == 0)
                        l = 0;
                }
                tmp = min(x[l], x[r]);
                if ((r - l) * tmp == w)
                {
                    for (int i = l; i <= r; i++)
                        ans[i] = tmp;
                    break;
                }
                else if ((r - l) * tmp > w)
                {
                    int mx = 0;
                    for (int i = l - 1; i >= 0; i--)
                    {
                        if (mx * (l - i - 1) + now + x[i] > w)
                        {
                            for (int j = i + 1; j < l; j++)
                                ans[j] = mx;
                            ans[i] = w - (mx * (l - i - 1) + now);
                            break;
                        }
                        mx = max(mx, x[i]);
                    }
                    break;
                }
                else
                {
                    now = (r - l) * tmp;
                }
            }
            else
            {
                for (int i = r + 1; i < n; i++)
                {
                    if (x[i] > x[r])
                    {
                        r = i;
                        break;
                    }
                    if (i == n - 1)
                        r = n - 1;
                }
                tmp = min(x[l], x[r]);
                if ((r - l) * tmp == w)
                {
                    for (int i = l; i <= r; i++)
                        ans[i] = tmp;
                    break;
                }
                else if ((r - l) * tmp > w)
                {
                    int mx = 0;
                    for (int i = r + 1; i < n; i++)
                    {
                        if (mx * (i - r - 1) + now + x[i] > w)
                        {
                            for (int j = i - 1; j > r; j--)
                                ans[j] = mx;
                            ans[i] = w - (mx * (i - r - 1) + now);
                            break;
                        }
                        mx = max(mx, x[i]);
                    }
                    break;
                }
                else
                {
                    now = (r - l) * tmp;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
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