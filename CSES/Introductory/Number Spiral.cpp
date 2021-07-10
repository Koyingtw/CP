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
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            int mx=max(n,m)-1;
            int ans=mx*mx;
            if(n==m)
            {
                ans=n*n-(n-1);
                cout<<ans<<endl;
                continue;
            }
            if(max(n,m)==n)
            {
                if(n%2)
                {
                    ans+=m;
                }
                else
                {
                    ans+=n*2-1;
                    ans-=(m-1);
                }
                cout<<ans<<endl;
                continue;
            }
            else 
            {
                if(m%2)
                {
                    ans+=m*2-1;
                    ans-=(n-1);
                }
                else
                {
                    ans+=n;
                }
                cout<<ans<<endl;
                continue;
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