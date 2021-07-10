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
const int W=10000;
void sol()
{
    int n;
    while(cin>>n)
    {
        pr x[n];
        int dp[W+1];//代表在重量i時的最大重量

        fr(i,0,n)
        {
            cin>>x[i].first>>x[i].second;
        }
        int w;
        cin>>w;
        sort(x,x+n);
        memset(dp,0,sizeof(dp));
        int mx=0;
        fr(i,0,n)
        {
            rf(j,w,x[i].first)
            {
                dp[j]=max(dp[j],dp[j-x[i].first]+x[i].second);
                mx=max(mx,dp[j]);
            }
        }
        cout<<mx<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}