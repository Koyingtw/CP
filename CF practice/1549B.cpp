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
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    cin >> n;
    string a, b;
    cin.ignore();
    cin >> a >> b;
    int ans = 0;
    fr(i, 0, n)
    {
        if (b[i] == '1')
        {
            if (a[i] == '0')
            {
                b[i] = '0';
                ans++;
            }
        }
    }
    fr(i, 0, n)
    {
        if (b[i] == '1')
        {
            if (i)
            {
                if (a[i - 1] == '1')
                {
                    a[i - 1] = '2';
                    b[i] = '0';
                    ans++;
                }
            }
        }
        if (b[i] == '1')
        {
            if (i < n - 1)
            {
                if (a[i + 1] == '1')
                {
                    a[i + 1] = '2';
                    b[i] = '0';
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}