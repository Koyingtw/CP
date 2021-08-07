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
        cin.ignore();
        pair<string, int> s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].F;
            s[i].S = i;
        }
        int ans[n];
        MEM(ans, 0);
        sort(s, s + n);
        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 0, len = min(s[i].F.size(), s[i + 1].F.size());
            for (int j = 0; j < len && s[i].F[j] == s[i + 1].F[j]; j++)
            {
                cnt++;
            }
            ans[s[i].S] = max(cnt, ans[s[i].S]);
            ans[s[i + 1].S] = max(cnt, ans[s[i + 1].S]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << endl;
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