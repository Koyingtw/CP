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
    int n,x;
    while(cin>>n>>x)
    {
        int a[n];
        fr(i,0,n) cin>>a[i];
        sort(a,a+n);
        int ans=0,r=n-1;

        fr(i,0,n)
        {
            if(i==r)
            {
                ans++;
                break;
            }
            rf(j,r,i)
            {
                if(a[i]+a[j]<=x)
                {
                    ans++;
                    r--;
                    break;
                }
                else 
                {
                    ans++;
                    r--;
                }
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