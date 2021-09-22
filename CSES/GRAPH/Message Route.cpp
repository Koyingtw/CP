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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

vector<int> v[200005];
int n, m;
int vis[200005];
bool out = 0;

void sol()
{
    while (cin >> n >> m)
    {
        vector<int> v[n + 1];
        int dis[n + 1];
        bool vis[n + 1];
        MEM(dis, 63);
        MEM(vis, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int e : v[u])
            {
                if (dis[e] > dis[u] + 1)
                {
                    dis[e] = dis[u] + 1;
                    q.push(e);
                }
            }
        }
        if (dis[n] > m)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            vector<int> ans;
            ans.push_back(n);
            int now = n;
            while (dis[n]--)
            {
                //cout << dis[n] << endl;
                for (int e : v[now])
                {
                    if (dis[e] == dis[n] && e != n)
                    {
                        ans.push_back(e);
                        now = e;
                        break;
                    }
                }
            }
            //ans.push_back(1);
            cout << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << endl;
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