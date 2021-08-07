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
    int n, m;
    while (cin >> n >> m)
    {
        int x[n], cnt = 0, ans = 0;
        queue<pr> q;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        pr pos{INF, -1};
        for (int i = 0; i < n; i++)
        {
            if (x[i] > x[m])
            {
                cnt++;
                if (x[i] - x[m] < pos.F)
                {
                    pos.F = x[i] - x[m];
                    pos.S = i;
                }
                else if (x[i] - x[m] == pos.F)
                {
                    pos.S = i;
                }
            }
        }
        if (pos.S == -1)
        {
            for (int i = 0; i < m; i++)
                if (x[i] == x[m])
                    cnt++;
        }
        else if (pos.S < m && pos.S != m - 1)
        {
            for (int i = pos.S + 1; i < n; i++)
                if (x[i] == x[m])
                    cnt++;
        }
        else if (pos.S > m)
        {
            for (int i = 0; i < m; i++)
                if (x[i] == x[m])
                    cnt++;
            for (int i = pos.S; i < n; i++)
                if (x[i] == x[m])
                    cnt++;
        }
        cout << cnt + 1 << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}