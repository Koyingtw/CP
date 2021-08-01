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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = n * m;
    bool yes = 0;
    if (n % 2 == 1 && k >= m / 2)
    {
        n--;
        cnt -= m;
        k -= m / 2;
    }
    while (k > m * 2)
    {
        k -= m * 2;
        cnt -= m * 2;
        k -= m;
    }
    if (k < 0 || m == 1 || n % 2)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0 && k % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (cnt == k * 2)
    {
        cout << "YES" << endl;
        return;
    }
    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void sol1()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = n * m;
    int all = 0;
    if (m > 1)
        all = (n - n % 2) * (m - m % 2) / 4;
    int a = 0, b = 0;
    if (m % 2 == 1)
        a = n / 2;
    if (n % 2 == 1)
        b = m / 2;
    k -= b;
    if (k < 0)
    {
        cout << "NO" << endl;
    }
    else if (k <= all * 2 && k % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol1();
    return 0;
}