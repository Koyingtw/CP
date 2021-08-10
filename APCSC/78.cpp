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

struct in
{
    int w, s, v;
    double cp;
};

bool cmp(in a, in b)
{
    if (a.w != b.w && a.s != b.s)
    {
        if (a.w <= b.s && b.w <= a.s)
            return a.s < b.s;
        return a.w <= b.s;
    }
    else if (a.w != b.w)
        return a.w < b.w;
    else if (a.s != b.s)
        return a.s < b.s;
    else
        return a.v > b.v;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        in x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].w >> x[i].s >> x[i].v;
        }
        sort(x, x + n, cmp);
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << x[i].w << " " << x[i].s << " " << x[i].v << endl;
        int ans = 0, weight = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i].s >= weight)
            {
                ans += x[i].v;
                weight += x[i].w;
            }
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