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
    int n, k;
    cin >> n >> k;
    if (n < k)
    {
        cout << "NO" << endl;
        return;
    }
    if ((n - k) % 2 == 0)
    {
        int cnt = 0;
        cout << "YES" << endl;
        fr(i, 0, k - 1)
        {
            cout << 1 << " ";
            cnt += 1;
        }
        cout << n - cnt << endl;
    }
    else if ((n - k * 2) >= 0 && (n - k * 2) % 2 == 0)
    {
        int cnt = 0;
        cout << "YES" << endl;
        fr(i, 0, k - 1)
        {
            cout << 2 << " ";
            cnt += 2;
        }
        cout << n - cnt << endl;
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
        {
            sol();
            END
        }
    return 0;
}