#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
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
    int x[2][7];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 7; j++)
            cin >> x[i][j];
    bool a = 0, b = 0, c = 0;
    for (int i = 0; i < 2; i++)
        if (x[i][1] == x[i][3] || x[i][1] != x[i][5])
            a = 1;
    if (x[0][6] != 1 || x[1][6] != 0)
        b = 1;
    if ((x[0][1] == x[1][1]) || (x[0][3] == x[1][3]) || (x[0][5] == x[1][5]))
        c = 1;
    if (a)
        cout << "A";
    if (b)
        cout << "B";
    if (c)
        cout << "C";
    if (!(a || b || c))
        cout << "None";
    cout << endl;
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