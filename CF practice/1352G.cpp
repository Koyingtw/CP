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
    if (n < 4)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 4)
    {
        cout << 3 << " " << 1 << " " << 4 << " " << 2 << endl;
        return;
    }
    if (n % 2 == 0)
    {
        int tmp = n;
        while (tmp > 0)
        {
            cout << tmp << " ";
            tmp -= 2;
        }
        cout << 5 << " " << 1 << " " << 3 << " ";
        tmp = 7;
        while (tmp <= n)
        {
            cout << tmp << " ";
            tmp += 2;
        }
        cout << endl;
    }
    else
    {
        int tmp = n;
        while (tmp > 0)
        {
            cout << tmp << " ";
            tmp -= 2;
        }
        cout << 4 << " " << 2 << " ";
        tmp = 6;
        while (tmp <= n)
        {
            cout << tmp << " ";
            tmp += 2;
        }
        cout << endl;
    }
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