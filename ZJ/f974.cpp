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
int p = 1000000007;

int f(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2)
        return (int)(x * f(x, n - 1)) % p;
    int a = f(x, n / 2) % p;
    return (int)(a * a) % p;
}

void sol()
{
    int x, n;

    while (cin >> x >> n && x * n)
    {
        if (x == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int ans = (int)((f(x, n + 1) + p - x) % p) / (x - 1) + 1;
        cout << ans % p << endl;
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