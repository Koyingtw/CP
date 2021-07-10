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
//#define int long long
#define itt signed
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int N,Q;
int A,B,C,D;
int l[200005],r[200005];
vector<int> x(200005);
int dfs(int deep,int i,int j,int mn)
{
    int r=-1,l=-1;
    fr(o,i+1,N) 
    {
        if(x[o]>x[i])
        {
          r=o;
          break;
        }
    }
    rf(o,i-1,0) 
    {
        if(x[o]>x[i])
        {
          l=o;
          break;
        }
    }
    if(l==j || r==j)
    {
        mn=min(mn,deep+1);
    }
    if(r!=-1) return dfs(deep+1,r,j,mn);
    if(l!=-1) return dfs(deep+1,l,j,mn);
    if(i>=A && i<=B)
    {
        if(mn==INT_MAX) return -1;
        return mn;
    }
    
}
int dp=-1;
int bfs(int i,int j,queue<int> q,queue<int> d)
{
    int r=-1,l=-1;
    int deep=d.front();
    dp=deep;
    d.pop();
    if(q.front()==j)
    {
        dp=deep;
        return deep;
    }
    q.pop();
    fr(o,i+1,N) 
    {
        if(x[o]>x[i])
        {
          r=o;
          break;
        }
    }
    
    rf(o,i-1,0) 
    {
        if(x[o]>x[i])
        {
          l=o;
          break;
        }
    }
    if(r!=-1)
    {
        q.push(r);
        if(d.empty()) d.push(1);
        else d.push(deep+1);
    }
    if(l!=-1)
    {
        q.push(l);
        if(d.empty()) d.push(1);
        else d.push(deep+1);
    }
    while(!(q.empty()))
    {
        return bfs(q.front(),i,q,d);
    }
    return -1;
}

void init(int N,vector<int> x)
{
    return;   
}
int minimum_jumps(int a,int b,int c,int d)
{
    A=a,B=b,C=c,D=d;
    int mn=INT_MAX;
    fr(i,a,b+1)
    {
      fr(j,c,d+1)
      {
        queue<int> q,d;
        q.push(i);
        d.push(0);
        bfs(i,j,q,d);
        return dp;
        //if(bfs(0,i,j,INT_MAX)!=-1) mn=min(mn,dfs(0,i,j,INT_MAX));
        //if(dfs(0,i,j,INT_MAX)!=-1) mn=min(mn,dfs(0,i,j,INT_MAX));
      }
    }
    if(mn==INT_MAX) mn=-1;
    return mn;
    
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>N>>Q)
    {
        init(N,x);
        fr(i,0,N) cin>>x[i];
        //fr(i,0,N) cout<<x[i]<<endl;
        while(Q--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<minimum_jumps(a,b,c,d)<<endl;
        }
    }
    return 0;
}
/*
7 4
3 2 1 6 4 5 7
4 4 6 6
1 3 5 6
0 1 2 2



*/