#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define uint long long
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

void pre()
{
    int tmp = 0;
    for (int i = 1; i < 100; i++)
    {
        tmp ^= i;
        cout << i << ": " << tmp << endl;
    }
}

int f(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    return n;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        uint cnt = 1;
        uint tmp = 1;
        uint ans = 0;
        cout << (f(m) ^ f(n - 1)) << endl;
    }
}

signed main()
{
    Koying;
    //pre();
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}