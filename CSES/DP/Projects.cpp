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
struct in
{
    int a, b, p;
} x[200005];
int dp[400005];

bool cmp(in q, in e)
{
    if (q.b != e.b)
        return q.a < e.a;
    else
        return q.b < e.b;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        set<int> s;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].a >> x[i].b >> x[i].p;
            s.insert(x[i].a);
            s.insert(x[i].b);
        }
        int cnt = 1;
        for (int it : s)
        {
            m[it] = cnt;
            cnt++;
        }
        for (int i = 0; i < n; i++)
        {
            x[i].a = m[x[i].a];
            x[i].b = m[x[i].b];
        }
        sort(x, x + n, cmp);
        //MEM(dp, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = x[i].a; j >= x[i - 1].b && j >= 0; j--)
                dp[x[i].a] = max(dp[x[i].a], dp[j]);
            dp[x[i].b] = max(dp[x[i].b], dp[x[i].a - 1] + x[i].p);
            ans = max(ans, dp[x[i].b]);
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