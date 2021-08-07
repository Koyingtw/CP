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
    int n, Q, first = 0, cnt = 0;
    cin >> n >> Q;
    queue<int> q[n], id;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        while (c--)
        {
            int a;
            cin >> a;
            m[a] = i;
        }
    }
    set<int> st;
    while (Q--)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            int i = m[b];
            if (st.count(i) == 0)
            {
                id.push(i);
                q[i].push(b);
                st.insert(i);
            }
            else
            {
                q[i].push(b);
            }
        }
        else
        {
            if (id.size())
            {
                cout << q[id.front()].front() << endl;
                q[id.front()].pop();
                if (q[id.front()].size() == 0)
                {
                    st.erase(id.front());
                    id.pop();
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}