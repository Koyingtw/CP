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

void sol()
{
    pr a, b, x;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> x.first >> x.second;
    int ans = abs(a.first - b.first);
    ans += abs(a.second - b.second);
    if (a.first == b.first && a.first == x.first)
    {
        if (x.second < b.second && x.second > a.second)
            ans += 2;
        if (x.second > b.second && x.second < a.second)
            ans += 2;
    }
    if (a.second == b.second && b.second == x.second)
    {
        if (x.F < b.F && x.F > a.F)
            ans += 2;
        if (x.F > b.F && x.F < a.F)
            ans += 2;
    }
    DB(ans);
}

signed main()
{
    Koying int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}