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

void sol()
{
    string s;
    cin >> s;

    int mn = 10;
    int a = 0, b = 0;
    int aa = 5, bb = 5;
    a = 0, b = 0;
    int tmp = 0;
    fr(i, 0, 10)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '1' || s[i] == '?')
                a++, aa--;
            if (a > b + bb)
                mn = min(mn, i + 1);
        }
        else if (s[i] == '1')
            b++, bb--;
        else
            bb--;
        if (a > b + bb)
            mn = min(mn, i + 1);
    }
    //cout << mn << endl;
    tmp = 0, a = 0, b = 0, aa = 5, bb = 5;
    fr(i, 0, 10)
    {
        if (i % 2 == 1)
        {
            if (s[i] == '1' || s[i] == '?')
                b++, bb--;
            if (b > a + aa)
                mn = min(mn, i + 1);
        }
        else if (s[i] == '1')
            a++, aa--;
        else
            aa--;
        if (b > a + aa)
            mn = min(mn, i + 1);
    }
    cout << mn << endl;
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