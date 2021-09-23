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
#define lowbit(x) x &(-x)
#define MAXN 200005
int bit[MAXN];
void update(int id, int val)
{
    while (id < MAXN)
    {
        bit[id] = max(bit[id], val);
        id += lowbit(id);
    }
}
int query(int id)
{
    int sum = 0;
    while (id)
    {
        sum = max(sum, bit[id]);
        id -= lowbit(id);
    }
    return sum;
}
void sol()
{
    int n;
    while (cin >> n)
    {
        int a[n], ans = 0;
        set<int> s;
        map<int, int> m;
        int dp[n];
        MEM(dp, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        int cnt = 2;
        for (int it : s)
        {
            m[it] = cnt;
            cnt++;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i] = query(m[a[i]] - 1) + 1;
            update(m[a[i]], dp[i]);
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
    }
    return 0;
}