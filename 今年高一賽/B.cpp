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
#define DB(a) cout<<a<<endl;
using namespace std;

void OUT(string s) {cout<<s; return;} 

void sol()
{
    int n;
    while(cin>>n)
    {
        int x[n],sum=0,ans=0;
        fr(i,0,n)
        {
            cin>>x[i];
        }
        sort(x,x+n);
        //sum=x[0];
        fr(i,0,n)
        {
            ans++;
            sum+=x[i];
            int find=upper_bound(x+i+1,x+n,sum)-x;
            if(find == n) break;
            else
            {
                i=find-1;
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