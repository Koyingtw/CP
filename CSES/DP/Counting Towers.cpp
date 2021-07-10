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
#define MEM(x, n) memset(x, n, sizeof(x));
#define stop system("pause");
using namespace std;

const int P = 1e9 + 7;

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            int n;
            while (cin >> n)
            {
                int dp[2][n + 1];
                MEM(dp[1], 0);
                MEM(dp[0], 0);
                dp[0][1] = 1;
                dp[1][1] = 1;
                fr(i, 2, n + 1)
                {
                    dp[0][i] = (4 * dp[0][i - 1] + dp[1][i - 1]) % P;
                    dp[1][i] = (dp[0][i - 1] + 2 * dp[1][i - 1]) % P;
                }
                cout << (dp[0][n] + dp[1][n]) % P << endl;
            }
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}

/*
該層有兩種分法，有橫貫中間的跟沒有橫貫的
即可由一層跟兩層的關係推導出DP式
(數數量即可)
*/