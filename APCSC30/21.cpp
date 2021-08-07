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
        int x[n];
        while (m--)
        {
            for (int i = 0; i < n; i++)
                cin >> x[i];
            stack<int> tmp, ans;
            int now = 1, i = n - 1;
            bool yes = 1;

            while (now <= n)
            {
                while (tmp.size() && tmp.top() == x[i])
                {
                    ans.push(x[i]);
                    tmp.pop();
                    i--;
                }
                if (now == x[i])
                {
                    ans.push(now);
                    i--;
                }
                else
                    tmp.push(now);
                while (tmp.size() && tmp.top() == x[i])
                {
                    ans.push(x[i]);
                    tmp.pop();
                    i--;
                }
                if (now == n && (ans.size() != n || tmp.size()))
                    yes = 0;
                now++;
            }
            if (!yes)
            {
                cout << "N" << endl;
            }
            else
                cout << "Y" << endl;
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