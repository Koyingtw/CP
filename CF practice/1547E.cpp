#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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
    int n, k;
    cin >> n >> k;
    int x[n + 1];
    MEM(x, 127);
    vector<pr> v;
    v.push_back({0, INF});
    fr(i, 1, k + 1)
    {
        int a;
        cin >> a;
        v.push_back({a, 0});
    }
    fr(i, 1, k + 1)
    {
        cin >> v[i].second;
        x[v[i].first] = v[i].second;
    }
    v.push_back({n + 1, INF});
    sort(v.begin(), v.end());
    fr(i, 1, k + 1)
    {
        v[i + 1].second = min(v[i + 1].second, v[i].second + v[i + 1].first - v[i].first);
        fr(j, v[i].first, v[i + 1].first)
        {
            x[j] = min(x[j], x[j - 1] + 1);
        }
    }

    rf(i, k, 1)
    {
        v[i - 1].second = min(v[i - 1].second, v[i].second - v[i - 1].first + v[i].first);
        rf(j, v[i].first - 1, v[i - 1].first)
        {
            x[j] = min(x[j], x[j + 1] + 1);
        }
    }
    fr(i, 1, n + 1)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
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