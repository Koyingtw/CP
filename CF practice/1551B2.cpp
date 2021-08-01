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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

bool cmp0(pr a, pr b)
{
    if (a.F != b.F)
    {
        return a.F < b.F;
    }
    return a.S < b.S;
}

bool cmp(pr a, pr b)
{
    return a.S < b.S;
}

void sol()
{
    int n, k;
    cin >> n >> k;
    //cout << n << " " << k << endl;
    int x[n];
    pr p[n];
    map<int, int> m;
    vector<int> ans;
    int sum = 0;
    fr(i, 0, n)
    {
        cin >> x[i];
        m[x[i]]++;
        if (m[x[i]] <= k)
            sum++;
        p[i].F = x[i];
        p[i].S = i;
    }
    sort(p, p + n, cmp0);
    map<int, int> mm;
    int cnt = min(sum / k, k);
    //DB(cnt);
    int now = 1;
    fr(i, 0, n)
    {
        mm[p[i].F]++;
        if (mm[p[i].F] > k)
        {
            p[i].F = 0;
        }
        else
        {
            p[i].F = now;
            now++;
            if (now > k)
                now = 1;
        }
    }
    if (p[n - 1].F != k)
    {
        rf(i, n - 1, 0)
        {
            if (p[i].F == k)
                break;
            p[i].F = 0;
        }
    }
    int a = 1;
    sort(p, p + n, cmp);
    fr(i, 0, n) cout << p[i].F << " ";

    cout << endl;
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