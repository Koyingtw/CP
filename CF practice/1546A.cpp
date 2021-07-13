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
    int sum = 0;
    fr(i, 0, n)
    {
        cin >> x[i];
        sum += x[i];
    }
    fr(i, 0, n)
    {
        cin >> y[i];
        sum -= y[i];
    }
    if (sum != 0)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    vector<pr> v;
    fr(i, 0, n)
    {
        if (x[i] > y[i])
        {
            ans += abs(x[i] - y[i]);
            int a = x[i] - y[i];
            fr(j, 0, n)
            {
                if (a <= 0)
                    break;
                if (i == j || x[j] >= y[j])
                    continue;
                while (x[j] < y[j])
                {
                    if (a <= 0)
                        break;
                    x[i]--;
                    x[j]++;
                    v.push_back({i, j});
                    a--;
                }
            }
        }
    }
    cout << ans << endl;
    fr(i, 0, ans)
    {
        cout << v[i].F + 1 << " " << v[i].S + 1 << endl;
    }
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