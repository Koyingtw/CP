#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int dp[1000005];
int p=1e9+7;
void sol()
{
    int n,x;
    while(cin>>n>>x)
    {
        int c[n];
        fr(i,0,n) cin>>c[i];
        sort(c,c+n);
        dp[0]=0;
        fr(i,1,x+1)
        {
            dp[i]=INT_MAX;
            fr(j,0,n)
            {
                if(i<c[j]) 
                {
                    //dp[i]=0;
                    break;
                }
                dp[i]=min(dp[i],dp[i-c[j]]+1)%p;
            }
            //cout<<dp[i]<<" ";
        }
        if(dp[x]==INT_MAX) cout<<-1<<endl;
        else cout<<dp[x]<<endl;
    }
}

signed main()
{
    Koying 
    sol();
    return 0;
}