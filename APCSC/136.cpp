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
    int l, n;
    cin >> l >> n;
    bool b[1005], yes = 0;
    MEM(b, 0);
    b[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (yes)
            continue;
        for (int j = l - a; j >= 0; j--)
        {
            if (b[j] == 1)
            {
                if (j + a < l)
                    b[j + a] = 1;
                else if (j + a == l)
                    yes = 1;
                else
                    break;
            }
        }
    }
    cout << (yes ? "TAK" : "NO") << endl;
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