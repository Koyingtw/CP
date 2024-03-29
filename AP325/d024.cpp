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
        int y[m], sum[n + 1];
        sum[0] = 0;
        fr(i, 0, n)
        {
            cin >> x[i];
            sum[i + 1] = sum[i] + x[i];
        }
        cin >> y[0];
        int find = lower_bound(sum, sum + n + 1, y[0]) - sum;
        int tmp = find % n;
        fr(i, 1, m)
        {
            cin >> y[i];
            find = lower_bound(sum, sum + n + 1, (y[i] + sum[tmp]) % sum[n]) - sum;
            tmp = find % n;
        }
        DB(tmp);
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