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
        int x[n], y[n];
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
            m[y[i]]++;
        }
        set<int> ans;
        for (int i = 0; i < n; i++)
        {
            map<int, int> mm = m;
            bool yes = 1;
            int now = x[0] ^ y[i];
            if (ans.count(now))
                continue;
            mm[y[i]]--;
            for (int j = 1; j < n; j++)
            {
                if (mm[now ^ x[j]])
                {
                    mm[now ^ x[j]]--;
                }
                else
                {
                    yes = 0;
                    break;
                }
            }
            if (yes)
                ans.insert(now);
        }
        cout << ans.size() << endl;
        for (int i : ans)
            cout << i << endl;
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