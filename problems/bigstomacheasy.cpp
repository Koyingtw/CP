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
    int n, q;
    while (cin >> n >> q)
    {
        int y[n], h[n], pre[n + 1], ans[n];
        pre[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
            pre[i + 1] = pre[i] + y[i];
            h[i] = sqrt(y[i]);
            //cout << h[i] << endl;
        }
        deque<pr> dq;
        dq.push_front({h[0], 0});
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {
            while (dq.size() && dq.front().F >= h[i])
                dq.pop_front();
            dq.push_front({h[i], i});
            while (dq.size() && tmp < n && dq.back().F - 1 < (i - tmp))
            {
                ans[tmp] = i - 1;
                tmp++;
                if (dq.back().S < tmp)
                    dq.pop_back();
            }
        }
        for (int i = tmp; i < n; i++)
            ans[i] = n - 1;
        // for (int i = 0; i < n; i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        while (q--)
        {
            int l;
            cin >> l;
            l--;
            cout << ans[l] - l + 1 << " " << pre[ans[l] + 1] - pre[l] << endl;
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
        END
    }
    return 0;
}