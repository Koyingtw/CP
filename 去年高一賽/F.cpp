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

bool cmp0(pr a,pr b)
{
    if(a.second/a.first != b.second/b.first)
    {
        return (a.second/a.first > b.second/b.first);
    }
    else return a.second>b.second;
}

void sol()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        pr x[n];
        pr avg[n];
        fr(i,0,n)
        {
            cin>>x[i].first>>x[i].second;
            avg[i].first=x[i].second/x[i].first;
            avg[i].second=i;
        }
        sort(x,x+n,cmp0);
        if(k==0)
        {
            int ans=0;
            fr(i,0,n)
            {
                if(x[i].first>=m)
                {
                    ans+=m*(x[i].second/x[i].first);
                    break;
                }
                else
                {
                    m-=x[i].first;
                    ans+=x[i].second;
                }
            }
            cout<<ans<<endl;
        }
        else if(k==1e9 || k>m)
        {
            int dp[m+1],ans=0;
            memset(dp,0,sizeof(dp));
            fr(i,0,n)
            {
                rf(j,m,x[i].first)
                {
                    dp[j]=max(dp[j],dp[j-x[i].first]+x[i].second);
                    ans=max(ans,dp[j]);
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}