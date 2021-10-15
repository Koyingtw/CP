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
    while (cin >> n)
    {
        int x[n], l[n], r[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            l[i] = i, r[i] = i;
        }
        stack<pr> sl, sr;
        sl.push({-1, -1});
        sr.push({-1, n});
        for (int i = 0; i < n; i++)
        {
            while (sl.size() && sl.top().F >= x[i])
                sl.pop();
            if (sl.size())
                l[i] = sl.top().S;
            else
                l[i] = 0;
            sl.push({x[i], i});
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (sr.size() && sr.top().F >= x[i])
                sr.pop();
            if (sr.size())
                r[i] = sr.top().S;
            else
                r[i] = n - 1;
            sr.push({x[i], i});
        }
        int ans = 0;
        // for (int it : l)
        //     cout << it << " ";
        // cout << endl;
        // for (int it : r)
        //     cout << it << " ";
        // cout << endl;
        for (int i = 0; i < n; i++)
            ans = max(ans, x[i] * (r[i] - l[i] - 1));
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
    }
    return 0;
}