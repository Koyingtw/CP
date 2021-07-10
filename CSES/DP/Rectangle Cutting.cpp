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
int dp[505][505];
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        if(n<m) swap(n,m);
        if(n == m)
        {
            cout<<0<<endl;
            continue;
        }
        fr(i,0,n+1)
            MEM(dp[i],127);
        dp[0][0]=0;
        dp[1][1]=0;
        fr(i,1,n+1)
        {
            fr(j,1,m+1)
            {
                if(i==1 && j==1)
                    continue;
                if(i == j)
                {
                    dp[i][j]=0;
                    continue;
                }
                int mn=INT_MAX;
                for (int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                }
                for (int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
        cout<<dp[n][m]<<endl;
        continue;
        fr(i,0,n)
        {
            fr(j,0,n)
            {
                cout<<dp[i+1][j+1]<<" ";
            }
            cout<<endl;
        }
        
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}