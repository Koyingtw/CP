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

void OUT(string s)
{
    cout << s;
    return;
}

signed dp[1000005] = {0, 1, 2, 4, 8, 16, 32, 63};
const int p = 1000000007;

void sol()
{
    int n;
    while (cin >> n)
    {
        if (n <= 6)
        {
            cout << dp[n] << endl;
        }
        else
        {
            fr(i, 7, n + 1)
            {
                fr(j, 1, 7)
                {
                    dp[i] += dp[i - j];
                    dp[i] %= p;
                }
            }
            cout << dp[n] % p << endl;
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}