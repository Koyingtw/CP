/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

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

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int n, m, x, y;
    while (cin >> n >> m >> x >> y)
    {
        int a[n + 1];
        fr(i, 0, n) cin >> a[i + 1];
        int dp[n + 1][3];
        fr(i, 0, n + 1)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        dp[1][0] = abs(x - a[1]);
        dp[1][1] = abs(y - a[1]);
        fr(i, 2, n + 1)
        {
            dp[i][0] = min(dp[i - 1][0] + abs(a[i] - a[i - 1]), dp[i - 1][1] + abs(a[i] - a[i - 1]));
            dp[i][1] = min(dp[i - 1][0] + abs(a[i] - a[i - 1]), dp[i - 1][1] + abs(a[i] - a[i - 1]));
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}