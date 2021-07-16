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
const int INF = 0x3f3f3f3f;
using namespace std;
/******************************************************************************/

bool cmp(pr a, pr b)
{
    return a.F < b.F;
}

void sol()
{
    int n;
    cin >> n;
    pr x[n];
    fr(i, 0, n)
    {
        cin >> x[i].F;
        x[i].S = i + 1;
    }
    sort(x, x + n, cmp);
    int ans = 0;
    fr(i, 1, n)
    {
        fr(j, 0, i)
        {
            if (x[i].F * x[j].F == x[i].S + x[j].S)
                ans++;
            if (x[i].F * x[j].F > 2 * n)
                break;
        }
    }
    DB(ans);
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}