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
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, q;
    while (cin >> n)
    {
        cin.ignore();
        string s;
        cin >> s;
        cin >> q;
        bool check = 0;
        while (q--)
        {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 1)
            {
                if (check)
                {
                    a += (a > n ? -n : n);
                    b += (b > n ? -n : n);
                    swap(s[a - 1], s[b - 1]);
                }
                else
                {
                    swap(s[a - 1], s[b - 1]);
                }
            }
            else
                check = (!check);
        }
        if (check)
        {
            for (int i = n; i < 2 * n; i++)
                cout << s[i];
            for (int i = 0; i < n; i++)
                cout << s[i];
            cout << endl;
        }
        else
            cout << s << endl;
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