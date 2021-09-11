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
int n, p, l, r;
int x[1000005];
int find(int i)
{
    if (i == 0)
        return 0;
    if (x[i] >= n || x[i] <= 0)
    {
        return 0;
    }
    if (x[i] != i)
    {
        return x[i] = find(x[i]);
    }
    else
        return i;
}
void sol()
{
    while (cin >> n >> p >> l >> r)
    {
        MEM(x, 0);
        bool vis[1000005];
        MEM(vis, 0);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
        {
            x[i] = find(i);
        }
        queue<pr> q; //{index, dis}
        int ans = -1;
        q.push({0, 0});
        while (q.size())
        {
            if (vis[q.front().F] == 1)
            {
                q.pop();
                continue;
            }
            vis[q.front().F] = 1;
            if (q.front().F == p)
            {
                ans = q.front().S;
                break;
            }
            if (q.front().F - l > 0)
            {
                if (x[q.front().F - l] > 0)
                    q.push({x[q.front().F - l], q.front().S + 1});
            }
            if (q.front().F + r < n)
            {
                if (x[q.front().F + r] < n)
                    q.push({x[q.front().F + r], q.front().S + 1});
            }
            q.pop();
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