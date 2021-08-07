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

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        pr x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i;
        }
        deque<pr> q;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            while (q.size() && q.front().F < x[i].F)
                q.pop_front();
            if (q.size() && i - q.back().S > m - 1)
                q.pop_back();
            q.push_front(x[i]);
        }
        ans.push_back(q.back().F);
        for (int i = m; i < n; i++)
        {
            while (q.size() && q.front().F < x[i].F)
                q.pop_front();
            if (q.size() && i - q.back().S > m - 1)
                q.pop_back();
            q.push_front(x[i]);
            ans.push_back(q.back().F);
        }
        for (int i : ans)
            cout << i << " ";
        cout << endl;
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