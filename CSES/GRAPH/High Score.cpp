/*
.-..-.             _
: :' ;            :_;
:   '  .--. .-..-..-.,-.,-. .--.
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include <bits/stdc++.h>
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 100000000000
#define MEM(x, n) memset(x, n, sizeof(x))

using namespace std;

struct Node
{
    int F, S, third;
};
int n, m;
int dist[2505], dist1[2505];
int cnt[2505];
bool rnd = 0, vis[2505][2505];
int can[2505][2505];
vector<Node> v;
bitset<2505> inque;
bool dfs(int i, int fa, int cnt, int tar)
{
    vis[i][fa] = 1;
    if (i == 1)
    {
        return cnt == tar;
    }
    bool rtn = 1;
    for (int e = 1; e <= n; e++)
    {
        if (e != i && can[e][i] && !vis[e][fa])
        {
            rtn &= dfs(e, i, cnt + can[e][i], tar);
        }
    }
    return rtn;
}

void sol()
{
    while (cin >> n >> m)
    {
        MEM(can, 0);
        for (int i = 0; i < 2505; i++)
            dist[i] = INF, can[i][i] = 1, dist1[i] = INF;
        dist[1] = 0, dist1[n] = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, dis;
            cin >> a >> b >> dis;
            v.push_back({a, b, -dis});
            can[a][b] = -dis;
        }
        bool yes = 1;
        for (int t = 0; t < n; t++)
        {
            for (int t = 0; t < n; t++)
            {
                for (Node i : v)
                {
                    if (dist[i.F] != INF)
                        dist[i.S] = min(dist[i.S], dist[i.F] + i.third);
                }
            }
        }
        for (Node e : v)
        {
            if (dist[e.F] != INF && dist[e.S] > dist[e.F] + e.third)
            {
                dist[e.S] = dist[e.F] + e.third;
                if (can[e.S][n])
                    yes = 0;
            }
        }
        int tmp = dist[n];

        // rnd = 0;
        // dfs(1);
        // if (rnd == 1)
        // {
        //     cout << -1 << endl;
        //     return;
        // }
        if (yes && dist[n] == dist1[1])
            cout << -dist[n] << endl;
        else
        {
            cout << -1 << endl;
            cout << dist[n] << " " << dist1[1] << endl;
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}