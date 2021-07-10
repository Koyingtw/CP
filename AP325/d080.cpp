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
int dp[21][10];

void pre()
{
    fr(j,0,10) 
    {
        dp[1][j]=1;
    }
    dp[1][0]=0;
    fr(i,2,21)
    {
        rf(j,9,0)
        {
            if(j<9) dp[i][j]=dp[i-1][j]+dp[i][j+1];
            else dp[i][j]=dp[i-1][j];
        }
    }
    
}

void out()
{
    fr(i,1,21)
    {
        for(int i:dp[i]) cout<<i<<" ";
        cout<<endl;
    }
}

void sol()
{
    string s;
    while(cin>>s)
    {
        int ans=0;
        int x[s.size()];
        fr(i,0,s.size()) x[i]=s[i]-'0';
        fr(i,0,x[0]) ans+=dp[s.size()][i];
        fr(i,1,s.size())
        {
            if(x[i]<x[i-1]) break;
            fr(j,x[i-1],x[i])
            {
                ans+=dp[s.size()-i][j];
            }
            if(i==s.size()-1) ans++;
        }
        cout<<ans<<endl;
    }
}


signed main()
{
    Koying
    pre();
    //out();
    sol();
    return 0;
}