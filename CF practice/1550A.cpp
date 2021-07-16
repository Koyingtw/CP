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
    int sum = 0;
    fr(i, 1, 5000)
    {
        sum += i * 2 - 1;
        if (sum >= n)
        {
            cout << i << endl;
            break;
        }
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