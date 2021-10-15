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
    int n, k;
    while (cin >> n >> k)
    {
        int x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        int l = 0, r = 0;
        map<int, int> m;
        m[x[0]] = 1;
        int ans = 1;
        for (r = 1; r < n; r++)
        {
            m[x[r]]++;
            while (m.size() > k)
            {
                m[x[l]]--;
                if (m[x[l]] == 0)
                    m.erase(x[l]);
                l++;
            }
            ans += r - l + 1;
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