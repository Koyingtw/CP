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

void sol()
{
    int n;
    cin >> n;
    int x[n];
    fr(i, 0, n)
    {
        cin >> x[i];
    }
    int l = 0, r = n - 1;
    int asum = 0, bsum = 0, ans = 0;
    int a = 0, b = 0;
    while (l <= r)
    {
        fr(i, l, r + 1)
        {
            a += x[i];
            l++;
            if (a > b)
                break;
        }
        ans++;
        asum += a;
        b = 0;
        if (l > r)
            break;
        rf(i, r, l)
        {
            b += x[i];
            r--;
            if (b > a)
                break;
        }
        bsum += b;
        a = 0;
        ans++;
    }
    cout << ans << " " << asum << " " << bsum << endl;
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