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
#define INFINITY 9223372036854775807
#define INF -INFINITY

using namespace std;

void sol()
{
    int n,m;
    while(cin>>n>>m)
    {
        int x[3][m],ans[n+1];
        bool can=0;
        //can.insert(1);
        memset(ans,128,sizeof(ans));
        ans[1]=0;
        //for(int i:ans) cout<<i<<endl;
        fr(i,0,m)
        {
            fr(j,0,3) 
            {
                cin>>x[j][i];
            }
            if(x[0][i]==n && x[1][i]==1) can=1;
            //if(can.count(x[0][i])) can.insert(x[1][i]);
            ans[x[1][i]]=max(ans[x[0][i]]+x[2][i],ans[x[1][i]]);
        }
        fr(k,0,n/2)
        {
            fr(i,0,m)
            
            {
                ans[x[1][i]]=max(ans[x[0][i]]+x[2][i],ans[x[1][i]]);
                //if(can.count(x[0][i])) can.insert(x[1][i]);
            }   
        }
        int mx=INF;
        if(can==0)
            cout<<ans[n]<<endl;
        else cout<<-1<<endl;
    }
}   


signed main()
{
    Koying
    sol();
    return 0;
}