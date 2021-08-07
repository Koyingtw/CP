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
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i + 1);
        int cnt = 1;
        vector<int> ans;
        while (q.size() > 1)
        {
            if (cnt % 2)
            {
                ans.push_back(q.front());
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            cnt++;
        }
        ans.push_back(q.front());
        while (m--)
        {
            int a;
            cin >> a;
            cout << ans[a - 1] << endl;
        }
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