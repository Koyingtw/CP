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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max(a, max(b, c));
    if (a == mx && a != b && a != c)
        cout << 0 << " ";
    else if (a == mx)
        cout << 1 << " ";
    else
        cout << mx - a + 1 << " ";
    if (b == mx && a != b && c != b)
        cout << 0 << " ";
    else if (b == mx)
        cout << 1 << " ";
    else
        cout << mx - b + 1 << " ";
    if (c == mx && a != c && b != c)
        cout << 0 << " ";
    else if (c == mx)
        cout << 1 << " ";
    else
        cout << mx - c + 1 << " ";
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
        }
    return 0;
}