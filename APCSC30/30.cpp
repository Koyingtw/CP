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
        multiset<int> s;
        while (n--)
        {
            int a, b;
            cin >> a;
            if (a == 1)
            {
                cin >> b;
                s.insert(b);
            }
            else if (a == 2)
            {
                if (s.size() == 0)
                {
                    cout << "EMPTY" << endl;
                    continue;
                }
                int ans = *s.begin();
                cout << ans << endl;
                s.erase(s.begin());
            }
            else if (a == 3)
            {
                if (s.size() == 0)
                {
                    cout << "EMPTY" << endl;
                    continue;
                }
                multiset<int>::iterator it = s.end();
                it--;
                int ans = *it;
                cout << ans << endl;
                s.erase(it);
            }
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