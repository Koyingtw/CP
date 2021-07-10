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
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
int k;
int n, m;
int x[300005][55];

void sol()
{
    int k;
    while (cin >> k)
    {
        int ans = k;
        cin >> n >> m;

        fr(i, 0, n)
        {
            MEM(x[i], 0)
            fr(j, 0, m)
            {
                int a;
                cin >> a;
                if (i == 0)
                {
                    if (j == 0)
                        x[i][j] = a;
                    else
                        x[i][j] = x[i][j - 1] + a;
                }
                else
                {
                    if (j == 0)
                        x[i][j] = x[i - 1][j] + a;
                    else
                        x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + a;
                }
                fr(o, 0, i + 1)
                {
                    fr(p, 0, j + 1)
                    {
                        if (i == o && p == j)
                        {
                            if (a <= k)
                                ans = min(ans, k - a);
                        }
                        else if (o == 0)
                        {
                            if (x[0][j] - x[0][p - 1] <= k)
                                ans = min(ans, k - (x[0][j] - x[0][p - 1]));
                        }
                        else if (p == 0)
                        {
                            if (x[i][0] - x[o - 1][0] <= k)
                                ans = min(ans, k - (x[i][0] - x[o - 1][0]));
                        }
                        else
                        {
                            int tmp;
                            tmp = x[i][j] - x[o - 1][j] - x[i][p - 1] + x[o - 1][p - 1];
                            if (tmp <= k)
                                ans = min(ans, k - tmp);
                        }
                    }
                }
            }
        }
        DB(k - ans);
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}