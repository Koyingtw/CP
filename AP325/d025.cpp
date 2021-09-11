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
int n, ans = 0;
vector<int> v[100005];

int dfs(int i)
{
    if (v[i].size() == 0)
        return 0;
    int mx = 0;
    for (int j : v[i])
    {
        int tmp = dfs(j);
        mx = max(mx, tmp);
    }
    ans += mx + 1;
    return mx + 1;
}

void sol()
{
    while (cin >> n)
    {
        set<int> s;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            int in;
            v[i].clear();
            while (t--)
            {
                cin >> in;
                v[i].push_back(in);
                s.insert(in);
            }
        }
        int tmp = 1;
        for (int i : s)
        {
            if (i != tmp)
            {
                break;
            }
            tmp++;
        }
        cout << tmp << endl;
        dfs(tmp);
        cout << ans << endl;
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