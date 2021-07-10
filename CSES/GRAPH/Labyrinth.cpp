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
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
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
#define endl '\n'
const int INF = 0x3f3f3f3f;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
char x[1005][1005];
int d[1005][1005];
int dis[1005][1005];
int px[4] = {1, -1, 0, 0};
int py[4] = {0, 0, 1, -1};
pr a, b;
string path = "DURL";
stack<char> s;
queue<pr> q;

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        fr(i, 0, n)
        {
            MEM(d[i], 0);
            MEM(dis[i], 0);
            fr(j, 0, m)
            {
                cin >> x[i][j];
                if (x[i][j] == 'A')
                    a = {i, j};
                if (x[i][j] == 'B')
                    b = {i, j};
            }
        }
        q.push(a);
        d[a.F][a.S] = 0;
        while (!q.empty())
        {
            pr tmp = q.front();
            q.pop();
            fr(i, 0, 4)
            {
                pr now;
                now.F = tmp.F + px[i];
                now.S = tmp.S + py[i];
                if (now.F >= 0 && now.S >= 0 && now.F < n && now.S < m && d[now.F][now.S] == 0)
                {
                    if (now == a || x[now.first][now.second] == '#')
                        continue;
                    q.push(now);
                    d[now.F][now.S] = d[tmp.F][tmp.S] + 1;
                    dis[now.F][now.S] = i;
                }
            }
        }
        if (d[b.F][b.S] == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<char> v;

        while (d[b.first][b.second] != 0)
        {
            pr tmp = b;
            fr(i, 0, 4)
            {
                pr now;
                now.F = tmp.F - px[i];
                now.S = tmp.S - py[i];
                if (d[tmp.F][tmp.S] == 1)
                {
                    if (now == a)
                    {
                        v.push_back(path[i]);
                        b = now;
                        break;
                    }
                }
                else if (now.F >= 0 && now.S >= 0 && now.F < n && now.S < m && d[now.F][now.S] == d[tmp.F][tmp.S] - 1)
                {
                    v.push_back(path[i]);
                    b = now;
                    break;
                }
            }
        }
        cout << "YES" << endl;
        cout << v.size() << endl;
        rf(i, v.size() - 1, 0) cout << v[i];
        cout << endl;
        cout.flush();
    }
}

signed main()
{
    Koying
    sol();

    return 0;
}