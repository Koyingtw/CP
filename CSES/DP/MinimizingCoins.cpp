#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
using namespace std;
int dp[1000005];
void sol()
{
    int n,x;
    while(cin>>n>>x)
    {
        int c[n];
        fr(i,0,n) cin>>c[i];
        sort(c,c+n);
        memset(dp,INT_MAX,sizeof(dp));
        if(x<c[0])
        {
            cout<<-1<<endl;
            continue;
        }
        dp[0]=0;
        fr(i,1,x+1)
        {
            fr(j,0,n)
            {
                if(i<c[j]) break;
                if(dp[i-c[j]]==-1) continue;
                dp[i]=min(dp[i],dp[i-c[j]]);
            }
            dp[i]++;
            //dp[i]-=(i==1);
        }
        cout<<(dp[x]>=0?dp[x]:-1)<<endl;
    }
}
 
signed main()
{
    sol();
}