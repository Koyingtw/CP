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

void sol()
{
    int k, n, m;
    cin >> k >> n >> m;
    int x[n], y[m];
    fr(i, 0, n)
    {
        cin >> x[i];
    }
    fr(i, 0, m)
    {
        cin >> y[i];
    }
    vector<int> ans;
    bool yes = 1;
    int a = 0, b = 0;
    while (a < n && b < m)
    {
        bool tmp = 0;
        while (a < n && x[a] <= k)
        {
            ans.push_back(x[a]);
            if (x[a] == 0)
                k++;
            a++;
            tmp = 1;
        }
        while (b < m && y[b] <= k)
        {
            ans.push_back(y[b]);
            if (y[b] == 0)
                k++;
            b++;
            tmp = 1;
        }
        if (a == n || b == m)
        {
            break;
        }
        if (tmp == 0)
        {
            yes = 0;
            break;
        }
    }
    fr(i, a, n)
    {
        if (x[i] <= k)
        {
            ans.push_back(x[i]);
            if (x[i] == 0)
                k++;
        }
        else
        {
            yes = 0;
            break;
        }
    }
    fr(i, b, m)
    {
        if (y[i] <= k)
        {
            ans.push_back(y[i]);
            if (y[i] == 0)
                k++;
        }
        else
        {
            yes = 0;
            break;
        }
    }
    if (yes)
    {
        for (int i : ans)
            cout << i << " ";
        cout << '\n';
    }
    else
        cout << -1 << '\n';
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