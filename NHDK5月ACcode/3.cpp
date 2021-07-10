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
        int a[n][m];
        bool b=1;
        fr(i,0,n)
        {
            fr(j,0,m) 
            {
                cin>>a[i][j];
            }
        }

        int x[2]={-1,-1};
        int y[2]={-1,-1};
        pr xx;
        pr yy;
        fr(i,0,n-2)//左上座標
        {
            fr(j,0,m-2)
            {
                fr(r,2,min(n,m))
                {
                    if(i+r>=n || j+r>=m) break;
                    bool yes=1;
                    fr(k,i,i+r+1)
                    {
                        fr(l,j,j+r+1)
                        {
                            if(a[k][l]==0 || yes==0)
                            {
                                yes=0;
                                break;
                            }
                        }
                    }
                    if(yes)
                    {
                        if(r>x[1]-x[0])
                        {
                            x[0]=i;
                            x[1]=i+r;
                            y[0]=j;
                            y[1]=j+r;
                        }
                        if(r==x[1]-x[0])
                        {
                            if(x[0]>i)
                            {
                                x[0]=i;
                                x[1]=i+r;
                                y[0]=j;
                                y[1]=j+r;
                            }
                        }
                    }
                }
            }
        }
        fr(i,x[0],x[1]+1)
        {
            fr(j,y[0],y[1]+1)
            {
                if(i==x[0] || i==x[1] || j==y[0] || j==y[1])
                {
                    a[i][j]=2;
                }
            }
        }
        if(x[0]==-1 ||y[0]==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        fr(i,0,n)
        {
            fr(j,0,m) cout<<a[i][j]<<" ";
            cout<<endl;
        }

    }
}

signed main()
{
    Koying
    sol();
}