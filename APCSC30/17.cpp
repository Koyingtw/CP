#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int short
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
    string s;
    cin >> s;
    int tmp = 0;
    bool yes = 1;
    for (register int i = 0; i < s.size(); i++)
    {
        tmp += (s[i] == '(');
        tmp -= (s[i] == ')');
        if (tmp < 0)
        {
            yes = 0;
            break;
        }
    }
    if (tmp != 0)
        yes = 0;
    if (yes)
        cout << "Y\n";
    else
        cout << "N\n";
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