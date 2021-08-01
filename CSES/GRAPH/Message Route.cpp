#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

vector<int> v[200005];
int n, m;
int vis[200005];
bool out = 0;

void dfs(int i, stack<int> s)
{
    if (out)
        return;
    s.push(i);
    if (i == 1)
    {
        out = 1;
        while (s.size())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        return;
    }
    for (int j : v[i])
    {
        if (vis[j] == vis[i] - 1)
        {
            dfs(j, s);
            break;
        }
    }
    return;
}

void sol()
{
    while (cin >> n >> m)
    {
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vis[1] = 1;
        queue<pr> q;
        q.push({1, 1});
        while (q.size())
        {
            pr now = q.front();
            q.pop();
            for (int i : v[now.F])
            {
                if (!vis[i])
                {
                    q.push({i, now.S + 1});
                }
                if (vis[i])
                    vis[i] = min(vis[i], now.S + 1);
                else
                    vis[i] = now.S + 1;
            }
        }
        if (vis[n] == 0)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            stack<int> ans;
            cout << vis[n] << endl;
            dfs(n, ans);
        }
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