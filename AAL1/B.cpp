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
int n, k, t;

bool cmp(pr a, pr b)
{
    if (a.S >= k && b.S >= k)
        return a.F > b.F;
    else
        return a.S >= k;
}

void sol()
{
    while (cin >> n >> k >> t)
    {
        pr x[n];
        for (int i = 0; i < n; i++)
            x[i] = {i + 1, 0};
        while (t--)
        {
            int a;
            cin >> a;
            x[a - 1].S++;
        }
        sort(x, x + n, cmp);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i].S < k)
                break;
            cnt++;
        }
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << x[i].F << " ";
        }
        cout << endl;
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