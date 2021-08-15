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

int f(int n) { return (1 + n * 2 - 1) * n / 2; }

void sol()
{
    int x, y;
    while (cin >> x >> y)
    {
        if (x == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (y == 0)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= y; i++)
        {
            int tmp = f(i);
            if (x == tmp)
            {
                cout << i << endl;
                break;
            }
            if ((x - tmp) % 2)
            {
                if (y != i)
                    continue;
                else
                {
                    cout << -1 << endl;
                    break;
                }
            }
            if (tmp > x)
            {
                cout << -1 << endl;
                break;
            }
            if ((x - tmp) <= (y - i) * 2 * i)
            {
                cout << i << endl;
                break;
            }
            if (i == y)
                cout << -1 << endl;
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