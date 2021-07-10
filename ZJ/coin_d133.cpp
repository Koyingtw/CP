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
const int coin[5]={1,5,10,25,50},N=30005;
int dp[5][N],cmx=0;
void pre()
{
    fr(i,0,5) memset(dp[i],0,sizeof(dp[i]));
    fr(j,0,N) 
    {
        dp[0][j]=1;
        fr(i,1,5)
        {
            if(j>=coin[i]) 
            {
                dp[i][j]=dp[i-1][j-coin[i]]+dp[i][j-coin[i]];
                //fr(k,0,i+1) dp[i][j]+=dp[k][j-coin[i]];
            }
        }
    }
}
void out(int n)
{
    int ans=0;
    fr(i,0,5) ans+=dp[i][n];
    if(ans-1>0) cout<<ans<<endl;
    else cout<<1<<endl;
}
void sol()
{
    int n;
    while(cin>>n)
    {
        out(n);
    }
}


signed main()
{
    Koying
    pre();
    sol();
    return 0;
}