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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int n, m;
    string a, b;
    while (cin >> a >> b)
    {
        n = a.size();
        m = b.size();
        int dp[n + 1][m + 1];
        fr(i, 0, n + 1) MEM(dp[i], 0);
        fr(i, 0, n + 1)
            dp[i][0] = i;
        fr(i, 0, m + 1)
            dp[0][i] = i;
        fr(i, 1, n + 1)
        {
            fr(j, 1, m + 1)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        DB(dp[n][m]);
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}

/*
-> 萊文斯坦距離，常用於分析DNA的相似程度
https://www.zhihu.com/question/315634571/answer/620984468
*/
