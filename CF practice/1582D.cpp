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
    int n;
    cin >> n;
    int x[n];
    int sum = 0, mn = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (x[i])
            mn = min(mn, abs(x[i]));
    }
    assert(mn != 0);
    int ans[n];
    MEM(ans, 0);
    for (int i = 0; i < n; i++)
    {
        if (abs(x[i]) % mn == 0)
        {
            if (sum > -1000 && !(sum >= 0 && sum <= 100 * abs(x[i])))
                ans[i] = (x[i] > 0 ? -1 : 1), sum += x[i] * (x[i] > 0 ? -1 : 1);
            else
                ans[i] = (x[i] > 0 ? 1 : -1), sum += x[i] * (x[i] > 0 ? 1 : -1);
        }
        else
        {
            int tar = mn; // x[i] / __gcd(x[i], mn);
            if (sum > -1000 && !(sum > 0 && sum <= mn * abs(x[i])))
                ans[i] = (x[i] > 0 ? -tar : tar), sum += x[i] * (x[i] > 0 ? -tar : tar);
            else
                ans[i] = (x[i] > 0 ? tar : -tar), sum += x[i] * (x[i] > 0 ? tar : -tar);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(x[i]) == mn)
        {
            assert(sum % x[i] == 0);
            ans[i] += -(sum / x[i]);
            if (ans[i] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (x[j] != 0 && i != j)
                    {
                        ans[j] += (ans[j] > 0 ? abs(mn) : -abs(mn));
                        ans[i] += (x[j] * (ans[j] > 0 ? abs(mn) : -abs(mn))) / x[i];
                        break;
                    }
                }
            }
            break;
        }
    }
    for (int it : ans)
        cout << it << " ";
    cout << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}