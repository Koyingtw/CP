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
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

pr mx = {0, 0};
bool visited[200005];
vector<int> v[10005];
void dfs(int i, int deep)
{
    visited[i] = true;

    if (deep > mx.F)
    {
        mx = {deep, i};
    }
    for (int j : v[i])
    {
        if (visited[j] == 0)
            dfs(j, deep + 1);
    }
    return;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int a;
            while (cin >> a && a != -1)
            {
                v[i].push_back(a);
                v[a].push_back(i);
            }
        }
        mx = {0, 0};
        dfs(0, 0);
        //cout << mx.F << " " << mx.S << endl;
        int tmp = mx.S;
        mx = {0, 0};
        MEM(visited, 0);
        dfs(tmp, 0);
        cout << mx.F << endl;
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