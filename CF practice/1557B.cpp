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

bool cmp(pr a, pr b) { return a.S < b.S; }

void sol()
{
    int n, m;
    cin >> n >> m;
    pr x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].F;
        x[i].S = i;
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        x[i].F = i + 1;
    sort(x, x + n, cmp);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (x[i].F != x[i - 1].F + 1)
        {
            cnt++;
            m--;
        }
    }
    m--;
    if (m >= 0)
        cout
            << "yes" << endl;
    else
        cout << "no" << endl;
    //cout << cnt << endl;
}
// -1 4 0 2 -> 1 4 2 3
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