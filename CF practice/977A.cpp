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
/******************************************************************************/

void sol()
{
    int t;
    string s;
    cin >> s >> t;
    rf(i, s.size() - 1, 0)
    {
        if (t - (s[i] - '0' + 1) < 0)
        {
            s[i] -= t;
            fr(j, 0, i + 1)
            {
                cout << s[j];
            }
            cout << endl;
            break;
        }
        else if (t - (s[i] - '0' + 1) == 0)
        {
            fr(j, 0, i)
            {
                cout << s[j];
            }
            cout << endl;
            break;
        }
        else
        {
            t -= (s[i] - '0' + 1);
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}