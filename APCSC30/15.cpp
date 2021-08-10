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

struct cmp
{
    bool operator()(pr a, pr b)
    {
        return a.F > b.F;
    }
};

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n], cnt = 0, ans = 0;
        int last = -1;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
        {
            if (x[i] > x[m])
            {
                cnt++;
                last = i;
            }
        }
        if (last == -1)
        {
            for (int i = 0; i <= m; i++)
            {
                if (x[i] == x[m])
                    cnt++;
            }
        }
        else if (last < m)
        {
            for (int i = last; i <= m; i++)
            {
                if (x[i] == x[m])
                    cnt++;
            }
        }
        else
        {
            for (int i = last; i < n; i++)
            {
                if (x[i] == x[m])
                    cnt++;
            }
            for (int i = 0; i <= m; i++)
            {
                if (x[i] == x[m])
                    cnt++;
            }
        }
        cout << cnt << endl;
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