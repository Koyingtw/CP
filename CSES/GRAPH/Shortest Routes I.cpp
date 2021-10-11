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
struct Node
{
    int a, b, dis;
};
bool operator<(const Node x, const Node y)
{
    if (x.dis != y.dis)
        return x.dis > y.dis;
    else
        return x.a > y.a;
}
vector<pr> v[100005];
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int dist[n + 1];
        MEM(dist, 0x3f);
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        dist[1] = 0;
        for (int i = 0; i < m; i++)
        {
            Node in;
            cin >> in.a >> in.b >> in.dis;
            v[in.a].push_back({in.b, in.dis});
        }
        pq.push({1, 0});
        while (pq.size())
        {
            pr now = pq.top();
            pq.pop();
            if (dist[now.F] != now.S)
                continue;
            for (pr it : v[now.F])
            {
                if (dist[it.F] > dist[now.F] + it.S)
                {
                    dist[it.F] = dist[now.F] + it.S;
                    pq.push({it.F, dist[it.F]});
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << dist[i] << " ";
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