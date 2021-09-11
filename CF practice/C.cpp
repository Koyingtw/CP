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
    int n;
    cin >> n;
    int sq = sqrt(n);
    if (sq * sq == n)
    {
        cout << sq << " " << 1 << endl;
        return;
    }
    if ((sq + 1) * (sq + 1) - sq == n)
    {
        cout << sq + 1 << " " << sq + 1 << endl;
        return;
    }
    if (n > (sq + 1) * (sq + 1) - sq)
    {
        cout << sq + 1 << " " << (sq + 1) * (sq + 1) - n + 1 << endl;
        return;
    }
    cout << n - sq * sq << " " << sq + 1 << endl;
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