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
    int n;
    cin >> n;
    int x[n];
    int y[n];
    int sum[2] = {0, 0}, ans[2] = {0, 0};
    set<int> s[2];
    fr(i, 0, n)
    {
        cin >> x[i];
        sum[0] += x[i];
    }
    fr(i, 0, n)
    {
        cin >> y[i];
        sum[1] += y[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    fr(i, 0, n / 4)
    {
        sum[0] -= x[i];
        sum[1] -= y[i];
    }
    if (sum[0] >= sum[1])
        cout << 0 << endl;
    int cnt = 0;
    int a = n / 4 - 1;
    while (sum[0] < sum[1])
    {
        //cout << sum[0] << " " << sum[1] << endl;
        cnt++;
        sum[0] += 100;
        int now = (n + cnt) / 4 - 1;
        if ((cnt + n) % 4 == 0)
        {
            sum[0] -= x[((cnt + n) / 4 - 1)];
        }
        if ((cnt + n) % 4 != 0 && a >= 0)
        {
            sum[1] += y[a--];
        }
        if (sum[0] >= sum[1])
        {
            cout << cnt << endl;
            break;
        }
    }
    cout << endl;
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