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
#define F first
#define S second
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define DB(a) cout<<a<<endl;
using namespace std;

void OUT(string s) {cout<<s; return;} 
int dp[10005]={0,0,6,28,96,252,550};

void pre()
{
    fr(i,7,10005)
    {
        int ans=0;
        ans+=(i-4)*(i-4)*8;
        ans+=(i-4)*4*6;
        ans+=(i-4)*4*4;
        ans+=16;
        ans+=24;
        ans+=8;
        dp[i]=i*i*(i*i-1)/2-ans/2;
    }
    return;
}
void sol()
{
    int n;
    while(cin>>n)
    {
        fr(i,1,n+1)
        {
            cout<<dp[i]<<endl;
        }
    }
}


signed main()
{
    Koying
    pre();
    sol();
    return 0;
}