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
const int INF = 0x3f3f3f3f;
using namespace std;
/******************************************************************************/

void sol()
{
    int n, m, k;
    cin >> n >> m >> k;

    int x[n];
    vector<int> ans;
    set<pr> s;
    fr(i, 0, m) s.insert({0, i + 1});

    fr(i, 0, n)
    {
        cin >> x[i];
        pr a = *s.begin();
        s.insert({a.F + x[i], a.S});
        s.erase(a);
        ans.push_back(a.S);
    }
    bool yes = 1;
    pr tmp = *s.begin();
    for (pr i : s)
    {
        if (i == *s.begin())
            continue;
        if (i.F - tmp.F > k)
        {
            yes = 0;
            break;
        }
        tmp = i;
    }
    if (yes)
    {
        cout << "YES" << endl;
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}