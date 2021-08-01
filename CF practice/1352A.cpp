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
    string s;
    cin >> s;
    int ans = 0;
    fr(i, 0, s.size())
    {
        if (s[i] != '0')
            ans++;
    }
    cout << ans << endl;
    fr(i, 0, s.size())
    {
        string a;
        if (s[i] != '0')
        {
            a += s[i];
            fr(j, 0, s.size() - i - 1) a += '0';
            cout << a << " ";
        }
    }
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