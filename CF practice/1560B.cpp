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

void sol()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b)
        swap(a, b);
    int mx = (a - b) * 2;
    if (a > mx || c > mx)
    {
        cout << -1 << endl;
        return;
    }
    if (c + (a - b) <= mx)
    {
        cout << c + (a - b) << endl;
    }
    else if (c - (a - b) > 0)
    {
        cout << c - (a - b) << endl;
    }
    else
        cout << -1 << endl;
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