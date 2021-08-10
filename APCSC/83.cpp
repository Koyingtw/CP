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
int n;
pr data[100005]; // 最大子樹、子孫數量
bool vis[100005];
vector<int> v[100005];
int mn;
int dfs(int i)
{
    vis[i] = 1;
    if (v[i].size() == 0)
    {
        data[i] = {n, 1};
        return 1;
    }
    else
    {
        int cnt = 0; //子孫數量
        int mx = 0;  //最大子樹
        for (int j : v[i])
        {
            if (vis[j] == 1)
            {
                int a = data[j].S;
                cnt += a;
                mx = max(mx, a);
            }
            int a = dfs(j);
            cnt += a;
            mx = max(mx, a);
        }

        mx = max(mx, n - cnt - 1);
        cnt++;
        mx++;
        data[i] = {mx, cnt};

        mn = min(mn, data[i].F);
        return data[i].S;
    }
}

void sol()
{
    while (cin >> n)
    {
        vector<pr> ans;
        MEM(vis, 0);
        mn = n;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            v[a].push_back(b);
        }
        dfs(0);
        for (int i = 0; i < n; i++)
        {
            if (data[i].F == mn)
                cout << i << endl;
            //cout << data[i].F << endl;
        }
        //cout << mn << endl;
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