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
bitset<100005> vis;
vector<int> v[100005], ans;
bool yes = 0;
void dfs(vector<int> rout, int i)
{
    rout.push_back(i);
    vis[i] = 1;
    if (yes)
        return;
    for (int e : v[i])
    {
        if (vis[e])
        {
            cout << rout.size() << endl;
            for (int it : rout)
                cout << it << " ";
            cout << e << endl;
            //yes = 1;
            return;
        }
        dfs(rout, e);
    }
}
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        vis.reset();
        int deg[n + 1] = {0}, a, b;
        while (m--)
        {
            cin >> a >> b;
            v[a].push_back(b);
            deg[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);
        while (q.size())
        {
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for (int e : v[now])
            {
                deg[e]--;
                if (deg[e] == 0)
                    q.push(e);
            }
        }
        int start = 1;
        if (ans.size() && ans.size() < n)
            start = ans[ans.size() - 1];
        if (ans.size() == n)
            cout << "IMPOSSIBLE" << endl;
        vector<int> rout;
        dfs(rout, start);
        for (int it : ans)
            cout
                << it << " ";
        cout << endl;
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