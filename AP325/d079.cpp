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
int dp[205][205];
int x[205];

void pre()
{
    fr(i,0,205)
    {
        for(int i:dp[i]) i=0;
    }
}

int f(int n,int m)
{
    if(dp[n][m]) return dp[n][m];
    if(m-n==1) return dp[m][n]=0;
    if(m-n==2) return dp[m][n]=x[m]-x[n];
    int mn=INT_MAX;
    fr(i,n+1,m)
    {
        mn=min(mn,x[m]-x[n]+f(n,i)+f(i,m));
    }
    //cout<<n<<" "<<m<<" "<<mn<<endl;
    return dp[n][m]=mn;
}

void sol()
{
    int n,L;
    while(cin>>n>>L)
    {
        pre();
        fr(i,1,n+1) cin>>x[i];
        x[0]=0,x[n+1]=L;
        cout<<f(0,n+1)<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}