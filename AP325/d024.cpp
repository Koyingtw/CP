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
    int n, m;
    while (cin >> n >> m)
    {
        int x[n];
        int y[m], sum = 0;
        cin >> x[0];
        fr(i, 1, n)
        {
            cin >> x[i];
            x[i] += x[i - 1];
        }
        cin >> y[0];
        int find = upper_bound(x, x + n, y[0]) - x;
        sum = x[find];
        fr(i, 1, m)
        {
            cin >> y[i];
            int tmp = find;
            find = upper_bound(x, x + n, y[i] + sum) - x;
            if (find == n)
            {
                sum -= x[n - 1];
                find = upper_bound(x, x + n, sum) - x;
            }
        }
        DB(find);
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}