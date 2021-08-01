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
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

pr rmq[100005][33];
int x[100005];

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        fr(i, 0, n)
        {
            cin >> x[i];
            rmq[i][0] = {x[i], x[i]};
        }
        fr(j, 1, 33)
        {
            if ((1 << j) > n)
                break;
            fr(i, 0, n)
            {
                int a = 1 << j;
                if (i + a > n)
                    break;
                a >>= 1;
                rmq[i][j].F = max(rmq[i][j - 1].F, rmq[i + a][j - 1].F);
                rmq[i][j].S = min(rmq[i][j - 1].S, rmq[i + a][j - 1].S);
            }
        }
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            a--;
            int r = (b - a), tmp = a, cnt = 0;
            int ans = 0;
            int mn = INF, mx = 0;
            while (r)
            {
                if (r % 2)
                {
                    mx = max(mx, rmq[tmp][cnt].F);
                    mn = min(mn, rmq[tmp][cnt].S);
                    //cout << rmq[tmp][cnt].F << " " << rmq[tmp][cnt].S << endl;

                    ans = max(ans, mx - mn);
                    tmp += 1 << cnt;
                }
                r >>= 1;
                cnt++;
            }
            //cout << mx << " " << mn << endl;
            cout << ans << endl;
        }
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