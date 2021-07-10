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
    int n,k;
    while(cin>>n>>k)
    {
        int x[n];
        fr(i,0,n) cin>>x[i];
        int dp[n];
        memset(dp,0,sizeof(dp));
        int ans=0;
        int a=2*k+1;
        pr mn;
        mn.first=INT_MAX;
        mn.second=0;
        fr(i,0,n)
        {
            if(x[i]<mn.first)
            {
                mn.first=x[i];
                mn.second=i;
            }
            a--;
            if(a==0)
            {
                ans+=mn.first;
                i=mn.second;
                mn.first=INT_MAX;
                a=2*k+1;
            }
        }
        cout<<ans<<endl;
    
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}