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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
struct Node
{
    int a, b, dis;
};
int start;
int n, m;
int cnt[2505], dist[2505];
vector<Node> v;
bitset<2505> vis;
int fa[2505];

void sol()
{
    while (cin >> n >> m)
    {
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            v.push_back({a, b, c});
        }
        MEM(dist, 63);
        int lastchange = 0;
        dist[1] = 0;
        for (int t = 1; t < n; t++)
        {
            for (Node e : v)
            {
                if (dist[e.a] != INF && dist[e.b] > dist[e.a] + e.dis)
                {
                    lastchange = e.b;
                    dist[e.b] = dist[e.a] + e.dis;
                    fa[e.b] = e.a;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << fa[i] << endl;
        //cout << lastchange << endl;
        if (!lastchange)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                lastchange = fa[lastchange];
            vector<int> ans;
            ans.push_back(lastchange);
            int tmp = fa[lastchange];
            while (tmp != lastchange)
            {
                tmp = fa[tmp];
                ans.push_back(tmp);
            }
            reverse(ans.begin(), ans.end());
            for (int it : ans)
                cout << it << " ";
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
    }
    return 0;
}