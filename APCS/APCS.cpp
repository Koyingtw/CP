#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x[n+1],m=n,mxx=0;
        bool b=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(x[i]>2*m)
            {
                b=1;
                mxx=max(mxx,x[i]);
            }
        }
        if(b)
        {
            cout<<mxx<<endl;
            continue;
        }
        int mx=0,sum=0;
        for(int i=1;i<=n;i++)
        {      
            sum=i;
            while(sum<=m)
            {
                sum+=x[sum];
                
            }
            sum-=i;
            mx=max(mx,sum);
        }
        cout<<mx<<endl;
        
    }
    

    return 0;
}