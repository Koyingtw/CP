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
        int x[n],y[n],a[n],sum=0;
        fr(i,0,n)
        {
            cin>>x[i];
        }
        fr(i,0,n)
        {
            cin>>y[i];
            sum+=y[i];
            a[i]=y[i]-x[i];
        }
        sort(a,a+n);
        fr(i,0,n)
        {
            sum-=a[i];
            if(sum<k)
            {
                cout<<i<<endl;
                break;
            }
        }
        if(sum>=k) cout<<n<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}