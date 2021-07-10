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
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define DB(a) cout << a << endl;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n][n], dp[n][n];
        fr(i, 0, n)
        {
            //memset(dp[i],-127,sizeof(dp[i]));
            fr(j, 0, n)
            {
                cin >> x[i][j];
                dp[i][j] = x[i][j];
            }
        }

        int mx = 0;
        rf(i, n - 1, 0)
        {
            rf(j, n - 1, 0)
            {
                if (i == n - 1)
                {
                    dp[i][j] = max(dp[i][j], (int)0);
                    if(j!=n-1) 
                        dp[i][j]=max(dp[i][j],dp[i][j+1]);
                    mx = max(mx, dp[i][j]);
                }
                else
                {
                    if (j != n - 1)
                    {
                        dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + x[i][j]);
                        dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                        dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                        dp[i][j] = max(dp[i][j], (int)0);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                        dp[i][j] = max(dp[i][j], (int)0);
                    }
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        cout << mx << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}