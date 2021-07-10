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
    int n,c;
    while(cin>>n>>c)
    {
        int x[n];
        fr(i,0,n)
        {
            cin>>x[i];
        }
        int dp[n+1],cnt[n+1];
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        int mx=0;
        fr(i,1,n)
        {
            dp[i]=dp[i-1];
            cnt[i]=cnt[i-1];
            bool yes=0;
            rf(j,i-1,0)
            {
                if(x[j]<x[i])
                {
                    yes=1;
                    if(dp[j]+x[i]-x[j]>dp[i])
                    {
                        dp[i]=dp[j]+x[i]-x[j];
                        cnt[i]=cnt[j]+1;
                    }
                }
            }
            mx=max(mx,dp[i]);
        }
        fr(i,0,n)
        {
            //cout<<dp[i]<<endl;
            if(dp[i]==mx)
            {
                cout<<mx<<" "<<cnt[i]<<endl;
                break;
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