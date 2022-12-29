
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
vector<pr> v[26];
vector<pr> vv[26];
int dis[26];
int start, fin;
bool vis[26];
vector<string> out;
void dfs(int i, stack<int> st)
{
    st.push(i);
    vis[i] = 1;
    if (i == start)
    {
        string tmp;
        while (st.size())
        {
            tmp += (char)(st.top() + 'A');
            st.pop();
        }
        out.push_back(tmp);
        vis[i] = 0;
        return;
    }
    for (pr e : vv[i])
    {
        if (dis[i] - dis[e.F] == e.S && !vis[e.F])
            dfs(e.F, st);
    }
    vis[i] = 0;
}
bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}
void sol()
{
    char c;
    char cc, ccc;
    cin >> c;
    start = c - 'A';
    cin >> cc;
    cin >> c;
    fin = c - 'A';
    int dist;
    while (cin >> c >> cc >> ccc >> cc >> dist && c != '-')
    {
        v[c - 'A'].push_back({ccc - 'A', dist});
        vv[ccc - 'A'].push_back({c - 'A', dist});
    }
    MEM(dis, 63);
    dis[start] = 0;
    queue<pr> q;
    q.push({start, 0});
    while (q.size())
    {
        pr now = q.front();
        q.pop();
        for (pr e : v[now.F])
        {
            if (dis[e.F] > dis[now.F] + e.S)
            {
                dis[e.F] = dis[now.F] + e.S;
                q.push({e.F, now.S + e.S});
            }
        }
    }
    if (dis[fin] > INF)
    {
        cout << "NOTFOUND" << endl;
        return;
    }
    cout << dis[fin] << endl;
    stack<int> ans;

    dfs(fin, ans);
    sort(out.begin(), out.end(), cmp);
    for (string it : out)
        cout << it << endl;
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