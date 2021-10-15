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
#define INF 0x3f3f3f3f
#define MEM(x, n) memset(x, n, sizeof(x))

using namespace std;
int n, m;
int dist[2505];
int cnt[2505];
bool rnd = 0, vis[2505];

vector<pr> v[2505];
bitset<2505> inque;

void dfs(int i)
{
    vis[i] = 1;
    for (pr e : v[i])
    {
        if (e.F != i && vis[e.F])
            rnd = 1;
        else if (!vis[e.F])
            dfs(e.F);
    }
    vis[i] = 0;
}
bool SFPA()
{
    MEM(cnt, 0);
    queue<int> q;
    q.push(1);
    inque[1] = 1;

    while (q.size())
    {
        int now = q.front();
        q.pop();
        inque[now] = 0;
        for (pr e : v[now])
            if (dist[e.F] < dist[now] + e.S)
            {
                if (++cnt[e.F] > n)
                    return false;
                dist[e.F] = dist[now] + e.S;
                if (inque[e.F] == 0)
                {
                    q.push(e.F);
                    inque[e.F] = 1;
                }
            }
    }
    return true;
}
void sol()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < 2505; i++)
            dist[i] = -INF;
        dist[1] = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, dis;
            cin >> a >> b >> dis;
            v[a].push_back({b, dis});
        }
        rnd = 0;
        dfs(1);
        if (rnd == 1)
        {
            cout << -1 << endl;
            return;
        }
        if (SFPA())
            cout << dist[n] << endl;
        else
        {
            int tmp = dist[n];
            //cout << tmp << endl;
            SFPA();
            if (dist[n] != tmp)
                cout << -1 << endl;
            else
                cout << dist[n] << endl;
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}