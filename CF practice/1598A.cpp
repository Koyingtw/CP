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
    int n;
    cin >> n;
    cin.ignore();
    string s[2];
    bool b[2][n];
    MEM(b, 0);
    cin >> s[0] >> s[1];
    b[0][0] = (s[0][0] - '0' == 0);
    b[1][0] = (s[1][0] - '0' == 0);
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            b[i][j] = (b[0][j - 1] or b[1][j - 1]);
            b[i][j] = (b[i][j] & (s[i][j] == '0'));
        }
    }
    if (b[1][n - 1])
        cout << "YES" << endl;
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
        }
    return 0;
}