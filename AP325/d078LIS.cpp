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
        int x[n];
        fr(i,0,n) cin>>x[i];
        int dp[n+1];
        memset(dp,127,sizeof(dp));
        fr(i,0,n+1) cout<<dp[i]<<endl;
        dp[0]=0;
        //dp[1]=x[0];
        int now=1;
        fr(i,0,n)
        {
            int find=lower_bound(dp,dp+n,x[i])-dp;//不大於
            if(find==n) continue;
            dp[find]=min(x[i],dp[find]);
            now=max(now,find);
            //cout<<x[i]<<" "<<find<<endl;
        }
        cout<<now<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}