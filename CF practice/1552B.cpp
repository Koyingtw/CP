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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n;
    cin >> n;
    int x[n][5];
    fr(i, 0, n)
    {
        fr(j, 0, 5)
        {
            cin >> x[i][j];
        }
    }
    int mx[5];
    int ans = 0;
    fr(i, 0, 5) mx[i] = x[0][i];
    fr(i, 1, n)
    {
        int cnt = 0;
        fr(j, 0, 5)
        {
            if (x[i][j] < mx[j])
                cnt++;
        }
        if (cnt >= 3)
        {
            ans = i;
            fr(j, 0, 5) mx[j] = x[i][j];
        }
    }
    bool yes = 1;
    fr(i, 0, n)
    {
        int cnt = 0;
        fr(j, 0, 5)
        {
            if (x[i][j] < mx[j])
                cnt++;
        }
        if (cnt >= 3)
            yes = 0;
    }
    if (yes)
        cout << ans + 1 << endl;
    else
        cout << -1 << endl;
}

void sol1()
{
    int n;
    cin >> n;
    int x[n][5];
    pr ans[n];
    fr(i, 0, n)
    {
        ans[i].S = i;
        ans[i].F = 0;
        fr(j, 0, 5)
        {
            cin >> x[i][j];
        }
    }
    bool b = 1;
    fr(i, 0, n - 1)
    {
        if (b == 0)
            break;
        fr(j, i + 1, n)
        {
            int a = 0, b = 0;
            fr(k, 0, 5)
            {
                if (x[i][k] < x[j][k])
                    a++;
                if (x[i][k] > x[j][k])
                    b++;
            }
            if (a > 2)
                ans[i].F++;
            if (b > 2)
                ans[j].F++;
            if (ans[i].F == n - 1 || ans[j].F == n - 1)
            {
                b = 0;
                break;
            }
        }
    }
    bool yes = 1;
    fr(i, 0, n)
    {
        //cout << ans[i].F << " ";
        if (ans[i].F == n - 1)
        {
            cout << i + 1 << "\n";
            yes = 0;
        }
    }
    if (yes)
        cout << -1 << "\n";
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            //END
        }
    return 0;
}