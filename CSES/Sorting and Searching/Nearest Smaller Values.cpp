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
int ans=-1;
int DQ(int x[],int l,int r,int n)
{
    if(r-l==1) 
    {
        if(x[l]<n)
        {
            return ans=max(ans,l);
        }
    }
    else if(r-l==2)
    {
        if(x[r-1]<n)
        {
            return ans=max(ans,r-1);
        }
        if(x[l]<n)
        {
            return ans=max(ans,l);
        }
    }
    else
    {
        int mid=(l+r)/2;
        return DQ(x,l,mid,n);
        DQ(x,mid,r,n);
    }
}
void sol()
{
    cout<<log2(1000)<<endl;
    int n;
    while(cin>>n)
    {
        int x[n];
        cin>>x[0];
        cout<<0<<" ";
        fr(i,1,n)
        {
            cin>>x[i];
        }
        fr(i,1,n)
        {
            ans=-1;
            DQ(x,0,i,x[i]);
            cout<<ans+1<<" ";
        }
        cout<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}