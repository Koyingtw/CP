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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, u, r, d, l;
    bool ans = 0;
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 16; i++)
    {
        bool tmp = 1;
        int cnt[4] = {0, 0, 0, 0};
        for (int j = 0; j < 4; j++)
        {
            if (i & (1 << j))
            {
                cnt[j]++;
                cnt[(j + 1) % 4]++;
            }
        }
        if (u < cnt[0] || u > cnt[0] + (n - 2))
            tmp = 0;
        if (r < cnt[1] || r > cnt[1] + (n - 2))
            tmp = 0;
        if (d < cnt[2] || d > cnt[2] + (n - 2))
            tmp = 0;
        if (l < cnt[3] || l > cnt[3] + (n - 2))
            tmp = 0;
        if (tmp)
            ans = 1;
    }
    if (ans)
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
        {
            sol();
        }
    return 0;
}