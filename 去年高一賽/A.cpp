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

using namespace std;
double f(int a,int b,int c)
{
    double ans=20*((double)a*1.25+(double)b*2.0+(double)c*1.0);
    ans/=(double)15*4.25;
    return ans;
}
double g(double n,double m)
{
    double ans=(double)(n+m)*0.4;
    return ans;
}
void sol()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        double n,m;
        cin>>n>>m;
        double tar;
        cin>>tar;
        //cout<<f(a,b,c)<<" "<<g(n,m)<<endl;
        cout<<(f(a,b,c)+g(n,m)>=tar?"YA":"QQ")<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}