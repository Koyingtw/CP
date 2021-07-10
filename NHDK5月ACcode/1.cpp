#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

void sol()
{
    int x[5];
        int sum=0;
        fr(i,0,5)
        {
            cin>>x[i];
            sum+=x[i];
        }
        int n;
        cin>>n;
        
        int ans=n/sum+(n%sum!=0);
        cout<<ans<<endl;
}

signed main()
{
    sol();
}