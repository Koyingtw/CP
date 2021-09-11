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
    int t;
    while (cin >> t)
    {
        queue<int> q;
        while (t--)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                int n;
                cin >> n;
                q.push(n);
            }
            else if (a == 2)
            {
                if (q.size())
                    q.pop();
                else
                    cout << "QQ" << endl;
            }
            else if (a == 3)
            {
                if (q.size())
                    cout << q.front() << endl;

                else
                    cout << "QQ" << endl;
            }
            else
            {
                cout << q.size() << endl;
            }
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