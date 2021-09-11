#pragma region
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
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n], sum[n] = {0};
        stack<pr> l, r;
        cin >> x[0];
        l.push({0, x[0]});
        sum[0] = 1;
        for (int i = 1; i < n; i++)
        {
            sum[i] = 1;
            cin >> x[i];
            bool yes = 0;
            while (l.size())
            {
                if (l.top().S >= x[i])
                {
                    l.pop();
                }
                else
                {
                    yes = 1;
                    break;
                }
            }
            if (yes)
            {
                sum[i] += i - l.top().F - 1;
            }
            else
                sum[i] += i;
            l.push({i, x[i]});
        }
        r.push({n - 1, x[n - 1]});
        for (int i = n - 2; i >= 0; i--)
        {
            bool yes = 0;
            while (r.size())
            {
                if (r.top().S >= x[i])
                {
                    r.pop();
                }
                else
                {
                    yes = 1;
                    break;
                }
            }
            if (yes)
            {
                sum[i] += r.top().F - i - 1;
            }
            else
            {
                sum[i] += n - 1 - i;
            }
            r.push({i, x[i]});
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, sum[i] * x[i]);
        }
        cout << ans << endl;
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