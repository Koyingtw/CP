
#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int dp[1000005];
int bit[1000005];
struct Node
{
    int a, b, w;
} x[1000005];
bool cmp(Node A, Node B)
{
    if (A.a != B.a)
        return A.a < B.a;
    else
        return A.b < B.b;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        vector<int> v;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].a >> x[i].b >> x[i].w;
            x[i].b++;
            v.push_back(x[i].a);
            // s.insert(x[i].a);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        // s.insert(1000000009);
        sort(x, x + n, cmp);
        ll ans = 0, mx = 0;
        int A, B;
        for (int i = 0; i < n; i++)
        {
            // mx = max(mx, dp[mp[x[i].a]]);
            A = lower_bound(v.begin(), v.end(), x[i].a) - v.begin() + 1;
            B = lower_bound(v.begin(), v.end(), x[i].b) - v.begin() + 1;
            dp[A] = max(dp[A], dp[A - 1]);
            dp[B] = max(dp[B], dp[A] + x[i].w);
            ans = max(ans, dp[B]);
            // update(B, dp[B]);
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