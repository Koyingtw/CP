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
        memset(ans,127,sizeof(ans));
        set<int> s;
        ans[1]=0;
        fr(i,0,m)
        {
            fr(j,0,3) 
            {
                cin>>x[j][i];
            }
            if(x[0][i]==1) s.insert(x[1][i]);
            ans[x[1][i]]=min(ans[x[0][i]]+x[2][i],ans[x[1][i]]);
        }
        int a=n-s.size();
        s.insert(1);
        fr(k,0,a)
        {
            if(s.size()==n) break;
            fr(i,0,m)
            {
                ans[x[1][i]]=min(ans[x[0][i]]+x[2][i],ans[x[1][i]]);
                if(ans[x[1][i]]<INT_MAX) s.insert(x[1][i]);
            }   
        }
        int mx=0;
        fr(i,1,n+1) 
        {
            mx=max(mx,ans[i]);
        }
        cout<<mx<<endl;
    }
}   

signed main()
{
    Koying
    sol();
    return 0;
}




