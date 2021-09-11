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
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int n, v;
int x[20];
vector<string> ans;
bool vis[20];
void dfs(queue<int> q, int i, int j, int cnt)
{
    q.push(j * x[i]);
    if (i == n - 1 && cnt == v)
    {
        string owo;
        owo += to_string(q.front());
        q.pop();
        while (q.size())
        {
            owo += '^' + to_string(q.front());
            q.pop();
        }
        owo += "=" + to_string(v);
        ans.push_back(owo);
        return;
    }
    if (i == n - 1)
        return;
    dfs(q, i + 1, 1, cnt ^ x[i + 1]);
    dfs(q, i + 1, 1, cnt);
}

void sol()
{
    while (cin >> n >> v)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        dfs(q, 0, 0, 0);
        dfs(q, 0, 1, x[0]);
        cout << ans.size() << endl;
        for (string i : ans)
            cout << i << endl;
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