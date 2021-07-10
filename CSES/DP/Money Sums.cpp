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

void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n];
        int sum=0;
        int ans=0;
        fr(i,0,n)
        {
            cin>>x[i];
            sum+=x[i];
        }
        sort(x,x+n);
        bool dp[n+1][sum+1];
        fr(i,0,n+1) 
            MEM(dp[i],0);
        dp[0][0]=1;
        fr(i,1,n+1)
        {
            fr(j,0,sum+1)
            {
                dp[i][j]=dp[i-1][j];
                if(j-x[i-1]>=0 && dp[i-1][j-x[i-1]])
                    dp[i][j]=1;
                if(i==n && dp[i][j])
                    ans++;
            }
            
        }
        DB(ans-1)
        fr(i,1,sum+1) 
        {
            if(dp[n][i])
                cout<<i<<" ";    
        }
        cout<<endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}