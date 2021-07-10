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
    int l,k,n;
    while(cin>>l>>k>>n)
    {
        int x[n],ans=l/k+(l%k!=0);
        pr mx;
        mx.first=INT_MAX,mx.second=-1;
        fr(i,0,n)
        {
            cin>>x[i];
            if(x[i]-ans<mx.first && (x[i]-ans)>=0)
            {
                mx.first=(x[i]-ans);
                mx.second=i;
            }
        }
        cout<<mx.second+1<<endl;

    }
}


signed main()
{
    Koying
    sol();
    return 0;
}