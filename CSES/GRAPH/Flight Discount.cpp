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

vector<pr> v[100005];
int dist0[100005], dist1[100005];
priority_queue<pr, vector<pr>, greater<pr>> pq; // cnt, edge
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            v[a].push_back({b, c});
        }
        MEM(dist0, 63);
        MEM(dist1, 63);
        dist0[1] = 0, dist1[1] = 0;
        bitset<100005> inque;
        inque.reset();

        pq.push({0, 1});
        while (pq.size())
        {
            pr now = pq.top();
            pq.pop();
            inque[now.S] = 0;
            // cout << now.S << endl;
            for (pr e : v[now.S])
            {
                if (dist0[e.F] > dist0[now.S] + e.S)
                {
                    dist0[e.F] = dist0[now.S] + e.S;
                    dist1[e.F] = min(dist1[e.F], dist0[now.S] + e.S / 2);
                    dist1[e.F] = min(dist1[e.F], dist1[now.S] + e.S);
                    if (!inque[e.F])
                        pq.push({dist0[e.F], e.F});
                    inque[e.F] = true;
                }
                dist1[e.F] = min(dist1[e.F], dist0[now.S] + e.S / 2);
                dist1[e.F] = min(dist1[e.F], dist1[now.S] + e.S);
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << dist0[i] << endl;
        cout << dist1[n] << endl;
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