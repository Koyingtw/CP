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
        set<int> s{0, m};
        int x[n];
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            x[b - 1] = a;
            //assert(a > 0 && a < m);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == m)
            {
                auto find = s.end();
                ans += *(prev(find)) - *(prev(find, 2));
                continue;
            }
            auto find = s.insert(x[i]).F;
            ans += *(next(find)) - *(prev(find));
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
/*
100 + 4 + 3 + 2 + 96

1 2 3 4 5


*/