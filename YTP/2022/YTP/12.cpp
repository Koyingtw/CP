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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    string a, b;
    while (cin >> a >> b)
    {
        int ans = 0;
        string tmp, ouo = "";
        for (int i = 0; i < min(a.size(), b.size()); i++)
        {
            ouo += a[i];
            tmp = ouo;
            tmp += ouo;
            for (int j = 0; j + (i + 1) * 2 <= b.size(); j++)
            {
                bool yes = 1;
                for (int k = 0; k < (i + 1) * 2; k++)
                {
                    if (b[j + k] != tmp[k])
                    {
                        yes = 0;
                        break;
                    }
                }
                ans += yes;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
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
    }
    return 0;
}