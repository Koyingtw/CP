#pragma region
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
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

bool cmp(pr a, pr b)
{
    return a.F < b.F;
}

void sol()
{
    int n, k;
    cin >> n >> k;
    vector<pr> v;
    bool b[n * 2 + 1];
    MEM(b, 0);
    fr(i, 0, k)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        v.push_back({x, y});
        b[x] = 1;
        b[y] = 1;
    }
    int ans = 0;
    int l = 0, r = 2 * n + 1;
    sort(v.begin(), v.end(), cmp);
    fr(i, 0, n - k)
    {
        int x, y, tmp;
        tmp = 0;
        fr(j, l + 1, r)
        {
            if (b[j] == 0)
            {

                x = j;
                l = j;
                break;
            }
        }
        tmp = n - k - i - 1;
        rf(j, r - 1, l + 1)
        {
            if (b[j] == 0)
            {
                if (tmp > 0)
                    tmp--;
                else
                {
                    y = j;
                    break;
                }
            }
        }
        int cnt = 0;
        v.push_back({x, y});
        b[x] = 1, b[y] = 1;
    }
    sort(v.begin(), v.end());
    fr(i, 0, n - 1)
    {
        fr(j, i + 1, n)
        {
            if (v[i].F < v[j].F && v[i].S < v[j].S && v[j].F < v[i].S)
                ans++;
        }
    }
    cout << ans << endl;
}

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