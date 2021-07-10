/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

void sol()
{
    int n;
    while(cin>>n)
    {
        int x[3][n];
        fr(i,0,n)
        {
            fr(j,0,3)
            {
                cin>>x[j][i];
            }
        }
        int dp[3][n];
        fr(i,0,3) memset(dp[i],127,sizeof(dp[i]));
        dp[0][0]=x[0][0];
        dp[0][1]=x[0][1]+dp[0][0];
        dp[0][2]=x[0][2]+dp[0][1];
        dp[1][1]=x[1][1]+x[0][0];
        dp[1][2]=min(dp[1][1],dp[0][1])+x[1][2];
        dp[2][2]=x[2][2]+dp[1][1];

        fr(i,0,3)
        {
            fr(j,3,n)
            {
                if(i) dp[i][j]=min( (dp[i-1][j-1]+x[i][j]) , (dp[i][j-1]+x[i][j]) );
                else dp[i][j]=dp[i][j-1]+x[i][j];
            }
        }
        int ans=INT_MAX;
        cout<<dp[2][n-1]<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}