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
    string a, b;
    cin >> a >> b;
    int ans = 0;
    fr(i, 0, a.size())
    {
        int x = 0;
        int y = 0;
        if (a[i] <= 'z' && a[i] >= 'a')
        {
            x = a[i] - 'a';
        }
        else
            x = a[i] - 'A';
        if (b[i] <= 'z' && b[i] >= 'a')
        {
            y = b[i] - 'a';
        }
        else
            y = b[i] - 'A';
        if (x != y)
        {
            if (x > y)
            {
                ans = 1;
                break;
            }
            else
                ans = -1;
            break;
        }
    }
    cout << ans << endl;
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