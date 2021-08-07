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
    int n;
    while (cin >> n)
    {
        int x[n];
        map<int, int> m;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        int l = 0, r = 0;
        pr ans = {0, 0};
        for (int i = 0; i < n; i++)
        {
            m[x[i]]++;
            r = i;
            if (m.size() == r - l + 1)
            {
                if (r - l > ans.S - ans.F)
                {
                    ans = {l, r};
                }
            }
            else
            {
                for (int j = l + 1; j < r; j++)
                {
                    m[x[j - 1]]--;
                    l = j;
                    if (!m[x[j - 1]])
                    {
                        m.erase(x[j - 1]);
                    }
                    if (m.size() == r - l + 1)
                    {
                        if (r - l > ans.S - ans.F)
                        {
                            ans = {l, r};
                        }
                        break;
                    }
                }
            }
        }
        for (int i = ans.F; i <= ans.S; i++)
            cout << x[i] << " ";
        cout << endl;
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