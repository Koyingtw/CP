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
    cin>>n;
    string s;
    while(cin>>s)
    {
        string ss;
        for(int i=0;i<s.size()*2+1;i++)
        {
            if(i%2==0) ss+="#";
            else ss+=s[i/2];
        }
        int l=0,r=0;
        for(int i=0;i<ss.size();i++)
        {
            int range=(r-l)/2;
            if(i+range>ss.size()||i-range<0) continue;
            if(ss[i-range]==ss[i+range])
            {
                bool b=1;
                for(int j=range;j>0;j--)
                {
                    if(ss[i+j]!=ss[i-j])
                    {
                        b=0;
                        break;
                    }
                }
                for(int j=range;b;j++)
                {
                    if(i+j>ss.size()||i-j<0) break;
                    if(ss[i+j]==ss[i-j])
                    {
                        r=i+j,l=i-j;
                    }
                    else break;
                }
            }
        }
        //#a#a#a#
        string ans;
        int cnt=0;
        for(int i=l;i<=r;i++)
        {
            if(ss[i]!='#') cout<<ss[i];
        }
        cout<<endl;
    }
}

signed main()
{
    Koying 
    sol();
    return 0;
}