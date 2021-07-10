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
//#define int long long
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
        pr p[n];
        int mx=0;
        fr(i,0,n)
        {
            cin>>p[i].first>>p[i].second;
            mx=max(mx,p[i].second);
        }
        int t;
        cin>>t;
        int dp[t+1];
        memset(dp,0,sizeof(dp));
        fr(i,0,n)
        {
            p[i].second=min(p[i].second,t);
            rf(j,p[i].second,1)
            {
                dp[j]=max(dp[j],dp[j-1]+p[i].first);
            }
        }
        int ans=0;
        fr(i,1,t+1) ans=max(ans,dp[i]);
        fr(i,1,t+1) 
        {
            if(dp[i]==dp[i-1] || dp[i]==0) ans--;
        }
        cout<<ans<<endl;
    }
}

bool cmp(pr a,pr b)
{
    if(a.second!=b.second) return a.second>b.second;
    else return a.first>b.first;
}
void re(pr &a)
{
    a.first=0;
}
void sol1()
{
    int n;
    while(cin>>n)
    {
        pr p[n];
        fr(i,0,n)
        {
            cin>>p[i].first>>p[i].second;
        }
        int t;
        cin>>t;
        sort(p,p+n,cmp);
        int ans=p[0].first-(t-p[0].second);
        int tmp=p[0].second-1;
        pr mx;
        mx.second=2;
        re(mx);
        fr(i,1,n)
        {
            if(p[i].second>tmp) 
            {
                if(p[i].first>mx.first) 
                {
                    mx.first=p[i].first;
                    mx.second=i;
                }
                continue;
            }
            if(p[i].second==tmp) 
            {
                if(p[i].first>mx.first) 
                {
                    ans+=p[i].first;
                    tmp--;
                    continue;
                }
                else 
                {
                    ans+=mx.first;
                    tmp--;
                    mx.first=0;
                    i=mx.second;
                    continue;
                }
                
            }
            if(p[i].second<tmp)
            {
                if(mx.first==0) 
                {
                    ans--;
                    tmp--;
                }
                else
                {
                    ans+=mx.first;
                    tmp--;
                    mx.first=0;
                    i=mx.second;
                    continue;
                }
            }
            if(tmp==0) break;
        }
        cout<<ans<<endl;
    }
}

signed main()
{
    Koying
    sol1();
    return 0;
}