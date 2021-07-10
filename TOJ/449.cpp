#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int sum=0;
int dfs(char x[],int i,int j,bool r,bool g,bool b,bool y)
{
    switch (x[i][j])
    {
    case '#':   
        return dfs(x,i,j,)
        break;
    
    default:
        break;
    }
}

void sol()
{
    int r,c;
    while(cin>>r>>c)
    {
        char x[r][c];
        fr(i,0,r)
            fr(j,0,c) cin>>x[i][j];
        int ans=INT_MAX;
        fr(i,0,r)
        {
            fr(j,0,c)
            {
                if(x[i][j]=='*')
                {
                    ans=min(ans,dfs(x,i,j,0,0,0,0));
                }
            }
        }
        cout<<ans<<endl;
    }
}

signed main()
{
    sol();
}