#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#define endl "\n"
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    register int n;
    while (cin >> n)
    {
        int x[n];
        long long ans = 0, sum = 0;
        for (register int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        for (int i = 0; i < n; i++)
        {
            sum += x[i];
            ans += sum;
        }
        cout << ans << "\n";
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