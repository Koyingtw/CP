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
#define MEM(x, n) memse t(x, n, sizeof(x));

#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
vector<int> v[100005];
bool vis[100005];
bool yes = 0;
vector<int> ans;
deque<int> path;
void dfs(int i, int pre)
{
    vis[i] = 1;
    path.push_back(i);
    if (yes)
        return;
    for (int e : v[i])
    {
        if (yes)
            return;
        if (!vis[e])
            dfs(e, i);
        else if (e != pre)
        {
            vis[e] = 1;
            path.push_back(e);
            bool b = 0;
            while (path.size())
            {
                if (b)
                    ans.push_back(path.front());
                else if (path.front() == e)
                {
                    ans.push_back(path.front());
                    b = 1;
                }
                path.pop_front();
            }
            cout << ans.size() << endl;
            for (int it : ans)
                cout << it << " ";
            cout << endl;
            yes = 1;
            return;
        }
    }
    if (path.size())
        path.pop_back();
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {

                dfs(i, 0);
                //path.clear();
            }
            if (yes)
                break;
        }
        if (!yes)
            cout << "IMPOSSIBLE" << endl;
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