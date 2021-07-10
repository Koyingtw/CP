#include<bits/stdc++.h>
#define int int
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int L,R;
bool cmp(pr a,pr b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int ans(int n,pr *a)
{
    int sum=0;
    int last=L,next=L;
    if(a[0].first>L) return INT_MAX;
    if(L==R)
    {
        fr(i,0,n+1)
        {
            if(i==n) return INT_MAX;
            if(a[i].first<=L && a[i].second >=R) return 1;
        }
    }

    fr(i,0,n+1)
    {
        if(i==n)
        {
            if(next<R && (L!=R)) return INT_MAX;
        }
        if(a[i].first>last)
        {
            last=next;
            sum++;
        }
        next=max(next,a[i].second);
    }
    if(next>=R) return sum;
    else return INT_MAX;
}

void sol()
{
    int a,b;
    while(cin>>a>>b)
    {
        pr x[a],y[b];
        fr(i,0,a) 
        {
            cin>>x[i].first>>x[i].second;
        }
        sort(x,x+a,cmp);
        fr(i,0,b) 
        {
            int aa,bb;
            cin>>aa>>bb;
            y[i].first=aa,y[i].second=bb;
        }
        sort(y,y+b,cmp);
        cin>>L>>R;
        int aa=ans(a,x);
        int bb=ans(b,y);
        if(aa<=bb && aa!=INT_MAX) cout<<"A WIN"<<endl;
        else if(aa>bb) cout<<"B WIN"<<endl; 
        else cout<<"TIE"<<endl;
    }
}


signed main()
{
    Koying 
    sol();
    return 0;
}