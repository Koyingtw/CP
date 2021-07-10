#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int f(char c) 
{
    return c-'0';
}

void sol()
{
    int n,m;
    while(cin>>n>>m)
    {
        int x[n+1][n+1];
        fr(i,0,n)
        {
            memset(x[i],0,sizeof(x[i]));
        }
        fr(i,0,m)
        {
            int a,b;
            cin>>a>>b;
            x[a][b]=1;
        }  
        
    }
}

signed main()
{
    Koying
    sol();
}