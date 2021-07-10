#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

bool cmp(int a,int b){return a>b;}

void sol()
{
    int n;
    while(cin>>n)
    {
        int x[n];
        fr(i,0,n) cin>>x[i];
        sort(x,x+n,cmp);
        if(n<4) 
            cout<<0<<endl;
        else
        {
            int ans=0;
            fr(i,0,n)
            {
                if(i%4==3)
                {
                    ans+=x[i]*x[i];
                }
            }
            cout<<ans<<endl;
        }
    }
}

signed main()
{
    sol();
}