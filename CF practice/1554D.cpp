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
    int n, m;
    while (cin >> n >> m)
    {
        string s;
        cin.ignore();
        cin >> s;
        int x[6][n];
        string a[6] = {"abc", "acb", "bca", "bac", "cab", "cba"};
        MEM(x, 0);
        fr(i, 0, s.size())
        {
            if (i)
            {
                fr(j, 0, 6)
                {
                    x[j][i] = x[j][i - 1];
                    if (s[i] != a[j][i % 3])
                        x[j][i]++;
                }
            }
            else
            {
                fr(j, 0, 6)
                {
                    x[j][i] = 0;
                    if (s[i] != a[j][i % 3])
                        x[j][i]++;
                }
            }
        }
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            int ans = INF;
            if (a > 1)
            {
                fr(i, 0, 6)
                {
                    ans = min(x[i][b - 1] - x[i][a - 2], ans);
                }
            }
            else
            {
                fr(i, 0, 6)
                {
                    ans = min(x[i][b - 1], ans);
                }
            }
            cout << ans << endl;
        }
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