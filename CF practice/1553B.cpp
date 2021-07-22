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
    string s, ss;
    cin >> s >> ss;
    bool yes = 0;

    fr(i, 0, s.size())
    {
        string tmp;
        fr(j, i, s.size())
        {
            tmp += s[j];
            if (tmp == ss || yes)
            {
                yes = 1;
                break;
            }
            string tt = tmp;
            rf(k, j - 1, 0)
            {
                tt += s[k];
                if (tt == ss || yes)
                {
                    yes = 1;
                    break;
                }
            }
        }
        string a;
        rf(k, i - 1, 0)
        {
            a += s[k];
            if (a == ss || yes)
            {
                yes = 1;
                break;
            }
        }
    }

    if (yes)
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
            sol();
    return 0;
}