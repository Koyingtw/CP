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
    int n, m, q;
    while (cin >> n >> m)
    {
        set<int> s[n + 1];
        int cnt = n;
        int x[n + 1];
        MEM(x, 0);
        fr(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            x[min(a, b)]++;
            if (x[min(a, b)] == 1)
                cnt--;
        }
        cin >> q;
        while (q--)
        {
            int a, l, r;
            cin >> a;
            if (a == 1)
            {
                cin >> l >> r;
                x[min(l, r)]++;
                if (x[min(l, r)] == 1)
                    cnt--;
            }
            if (a == 2)
            {
                cin >> l >> r;
                x[min(l, r)]--;
                if (x[min(l, r)] == 0)
                    cnt++;
            }
            if (a == 3)
            {
                cout << cnt << endl;
            }
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    //while (1)
    {
        sol();
        END
    }
    return 0;
}