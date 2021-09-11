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
    int n;
    while (cin >> n)
    {
        int x[n], ans = 1;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        int l = 0, r = 0;
        map<int, int> m;
        m[x[0]]++;
        while (++r && r < n)
        {
            m[x[r]]++;
            while (m.size() != r - l + 1)
            {
                m[x[l]]--;
                if (!m[x[l]])
                    m.erase(x[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
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
        END
    }
    return 0;
}