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
    string s;
    while (cin >> s)
    {
        map<char, int> m;
        int l = 0, r = 0;
        pr ans = {0, INF};
        for (int i = 0; i < s.size(); i++)
        {
            r = i;
            m[s[i]]++;
            if (m.size() == 26)
            {
                for (int j = l; j < r; j++)
                {
                    l = j;
                    if (m[s[j]] == 1)
                    {
                        if (r - l < ans.S - ans.F)
                        {
                            ans = {l, r};
                        }
                        break;
                    }
                    m[s[j]]--;
                }
            }
        }
        if (ans.S == INF)
        {
            cout << "QQ" << endl;
            continue;
        }
        //cout << ans.F << " " << ans.S << endl;
        for (int i = ans.F; i <= ans.S; i++)
        {
            cout << s[i];
        }
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