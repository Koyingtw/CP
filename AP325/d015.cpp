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
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int x[n], y[m];
        fr(i, 0, n) cin >> x[i];
        fr(i, 0, m) cin >> y[i];
        sort(x, x + n);
        sort(y, y + m);
        int tmp = m - 1, ans = 0;
        fr(i, 0, n)
        {
            if (tmp == -1)
                break;
            if (x[i] + y[tmp] < k)
                continue;
            if (x[i] + y[tmp] == k)
                ans++;
            if (x[i] + y[tmp] > k)
                tmp--, i--;
        }
        DB(ans);
    }
}
/*
-3 1 6
-3 -1 1 5

*/
signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}