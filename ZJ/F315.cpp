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
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
int BIT[MAXN];

int query(int x)
{
    int sum = 0;
    while (x)
    {
        sum += BIT[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x)
{
    while (x < MAXN)
    {
        BIT[x]++;
        x += lowbit(x);
    }
}

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[2 * n], cnt[n + 1];
        MEM(cnt, 0);
        int ans = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> x[i];
            if (!cnt[x[i]])
                cnt[x[i]] = query(x[i]) + 1;
            else
                ans += query(x[i]) - cnt[x[i]];
            update(x[i]);
        }
        cout << ans << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    // while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}