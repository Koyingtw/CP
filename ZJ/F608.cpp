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

#define MAXN 200005
#define lowbit(x) x &(-x)

int BIT[MAXN];
int query(int i)
{
    int sum = 0;
    while (i)
    {
        sum = max(BIT[i], sum);
        i -= lowbit(i);
    }
    return sum;
}

void update(int i, int val)
{
    while (i < MAXN)
    {
        BIT[i] = max(BIT[i], val);
        i += lowbit(i);
    }
    return;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        int dp[n];
        int ans = 0;
        MEM(BIT, 0);
        MEM(dp, 0);
        set<int> s;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F >> x[i].S;
            s.insert(x[i].S);
        }
        sort(x, x + n);
        int cnt = 1;
        for (int i : s)
        {
            m[i] = cnt;
            cnt++;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i] = query(m[x[i].S]) + 1;
            update(m[x[i].S], dp[i]);
            ans = max(ans, dp[i]);
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