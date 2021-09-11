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
#define lowbit(x) x &(-x)

bool cmp(pr a, pr b)
{
    return a.S < b.S;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n], pos[n], ans = 1;
        set<int> s;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            s.insert(x[i]);
        }
        int tmp = 0;
        for (int i : s)
        {
            mp[i] = tmp;
            tmp++;
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = mp[x[i]];
            pos[x[i]] = i;
        }
        for (int i = 1; i < n; i++)
        {
            if (pos[i] < pos[i - 1])
                ans++;
        }
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            int owo = 0;
            if (x[a] != 0)
                owo += (pos[x[a]] < pos[x[a] - 1]);
            if (x[a] != n - 1)
                owo += (pos[x[a] + 1] < pos[x[a]]);
            if (x[b] - x[a] != 1 && x[b])
                owo += (pos[x[b]] < pos[x[b] - 1]);
            if (x[b] != n - 1 && x[b] != x[a] - 1)
                owo += (pos[x[b] + 1] < pos[x[b]]);

            swap(pos[x[a]], pos[x[b]]);
            swap(x[a], x[b]);
            if (x[a] != 0)
                owo -= (pos[x[a]] < pos[x[a] - 1]);
            if (x[a] != n - 1)
                owo -= (pos[x[a] + 1] < pos[x[a]]);
            if (x[b] - x[a] != 1 && x[b])
                owo -= (pos[x[b]] < pos[x[b] - 1]);
            if (x[b] != n - 1 && x[b] != x[a] - 1)
                owo -= (pos[x[b] + 1] < pos[x[b]]);
            ans -= owo;
            cout << ans << endl;
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