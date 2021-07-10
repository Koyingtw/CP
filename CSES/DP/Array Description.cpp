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
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define DB(a) cout << a << endl;
using namespace std;
int N = 1e5 + 5;
int M = 105;
int P = 1000000007;
void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n];
        int dp[2][m + 1];
        int path[3] = {-1, 0, 1};
        int ans = 0;
        memset(dp[0], 0, sizeof(dp[0]));
        memset(dp[1], 0, sizeof(dp[1]));
        fr(i, 0, n)
        {
            cin >> x[i];

            if (i == 0 && x[i])
                dp[0][x[i]] = 1;
            else if (i == 0 && x[i] == 0)
            {
                fr(j, 1, m + 1)
                    dp[0][j] = 1;
            }
        }
        fr(i, 1, n)
        {
            memset(dp[i % 2], 0, sizeof(dp[i % 2]));
            if (x[i] == 0)
            {
                fr(j, 1, m + 1)
                {
                    for (int k : path)
                    {
                        if (j + k > 0 && j + k <= m)
                        {
                            dp[i % 2][j] += dp[(i + 1) % 2][j + k];
                            dp[i % 2][j] %= P;
                        }
                    }
                }
            }
            else
            {
                for (int k : path)
                {
                    if (x[i] + k > 0 && x[i] + k <= m)
                    {
                        dp[i % 2][x[i]] += dp[(i + 1) % 2][x[i] + k];
                        dp[i % 2][x[i]] %= P;
                    }
                }
            }
        }
        fr(i, 1, m + 1) ans += dp[(n - 1) % 2][i];
        cout << ans % P << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}