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

/*int pw(int a)
{
    while(a)
    {
        if(a%2)
    }
}*/

void sol()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int a,b;
            cin>>a>>b;
            int p=pow(2,a);
            b%=p;
            //int x[p];
            bool bl[2305843009213693952];
            //memset(bl,0,sizeof(bl));
            fr(i,0,2305843009213693952) cout<<bl[i]<<endl;
            cout<<sizeof(bl)<<endl;
            //cout<<sizeof(x)<<endl;
            fr(i,0,b)
            {
                int j=1;
                while(1)
                {
                    if(j>p/2)
                    {
                        if(i==b-1) cout<<j<<endl;
                        break;
                    }
                    if(bl[j])
                    {
                        bl[j]=0;
                        j=2*j+1;
                    }
                    else
                    {
                        bl[j]=1;
                        j=2*j;
                    }
                }
            }
            
        }
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}