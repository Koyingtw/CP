#pragma region
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
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#define DB(a) cout << a << endl;
#else
#define stop         \
    system("pause"); \
    return 0;
#define DB(a) //
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
vector<int> v[200005];
int x[200005];
int cnt = 0;
bool visited[200005];
vector<int> ans;
void dfs(int i)
{
    if (x[i] == 0)
    {
        ans.push_back(i);
        visited[i] = 1;
        return;
    }
    if (x[i] % 2)
        return;
    visited[i] = true;
    ans.push_back(i);
    for (int j : v[i])
    {
        if (visited[j] == 0)
        {
            x[j]--;
            dfs(j);
        }
    }
    return;
}

void sol()
{
    int n;
    cin >> n;
    int yes = 1;

    MEM(x, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a)
        {
            v[a].push_back(i);
            v[i].push_back(a);
            x[a]++;
            x[i]++;
        }
    }
    int root;
    while (ans.size() < n)
    {
        bool b = 0;
        for (int i = 1; i <= n; i++)
        {
            if (x[i] % 2 == 0 && visited[i] == 0)
            {
                b = 1;
                dfs(i);
            }
        }
        if (b == 0)
            break;
    }
    if (ans.size() < n)
    {
        cout << "NO" << endl;
        return;
    }
    else
        cout << "YES" << endl;
    for (int i : ans)
        cout << i << endl;
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
    stop;
}
/*
8
3 1 4 0 4 2 4 5
2 2 2 2 2 1 1 1


*/