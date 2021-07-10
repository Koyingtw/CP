#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

void sol()
{
    int n;
    while(cin>>n)
    {
        priority_queue<int> pqa,pqb;
        int suma=0,sumb=0; 
        fr(i,0,n)
        {
            int a,b,c;
            cin>>a>>b>>c;
            pqa.push(a);
            pqb.push(b);
            if(c)
            {
                int aa,bb;
                aa=pqa.top();
                bb=pqb.top();
                pqa.pop();
                pqb.pop();
                suma+=aa;
                sumb+=bb;
                pqa.push(bb);
                pqb.push(aa);
            }
        }
        cout<<sumb<<" "<<suma<<endl;
    }
}

signed main()
{
    sol();
}