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
int dp[2][100000000];//dp[i][j]代表第j天時有幾個性別為i的 0為雌姓 1為雄性
void pre()
{
    dp[0][0]=1;
    
    fr(i,1,100000000)
    {
        dp[0][i]=(dp[1][i-1]+dp[0][i-1])%100000007;
        dp[1][i]=(dp[0][i-1])%100000007;
    }
}

void sol()
{
    int m,f,k;
    while(cin>>m>>f>>k)
    {
        if(k>0)
        {
            int ans=0;
            ans+=f*(dp[0][k]+dp[1][k]);
            ans+=m*(dp[0][k-1]+dp[1][k-1]);
            cout<<ans<<endl;
        }
        else cout<<f+m<<endl;
    }
}


signed main()
{
    Koying
    pre();
    sol();
    return 0;
}