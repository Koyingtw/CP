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
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=x[0];
        dp[1]=max(x[1],x[0]);
        fr(i,2,n)
        {
            dp[i]=max(dp[i-1],dp[i-2]+x[i]);
        }
        cout<<dp[n-1]<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}