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

bool cmp(pr a, pr b) { return a.S <= b.S; }

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i].F >> x[i].S;
        sort(x, x + n);
        int ans = 0, tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp += x[i].F;
            ans += x[i].S - tmp;
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