#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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
int dep[400005];
void sol()
{
    int n, k;
    int a, b;
    cin >> n >> k;
    if (n == 1 && k)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> v[n + 1];
    int deg[n + 1];
    MEM(deg, 0);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    queue<pr> q;
    MEM(dep, 0);
    for (int i = 1; i <= n; i++)
        if (v[i].size() <= 1)
            q.push({i, 1});

    while (q.size())
    {
        pr now = q.front();
        q.pop();
        dep[now.F] = now.S;
        deg[now.F] = 0;
        for (int e : v[now.F])
        {
            deg[e]--;
            if (deg[e] == 1)
                q.push({e, now.S + 1});
        }
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
        if (dep[i] <= k)
            ans--;
    cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}