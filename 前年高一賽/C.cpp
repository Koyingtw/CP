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

void OUT(string s) {cout<<s; return;} 

void sol()
{
    string a,b;

    while(cin>>a>>b)
    {
        bool A,B,yes=1;
        A=(a[0]=='-');
        B=(b[0]=='-');
        if(A && B) // --
        {
            if(a.size()<b.size()) yes=0;
            if(a.size()==b.size())
            fr(i,1,a.size())
            {
                if(a[i]<b[i]) 
                {
                    yes=0;
                    break;
                }
            }
            if(yes) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        if(A && !B) // -+
        {
            cout<<"YES"<<endl;
        }
        if(!A && B)
        {
            cout<<"NO"<<endl;
        }
        if(!A && !B)
        {
            if(b.size()<a.size()) yes=0;
            if(b.size()==a.size())
            {
                fr(i,0,a.size())
                {
                    if(b[i]<a[i]) 
                    {
                        yes=0;
                        break;
                    }
                }
                
            }
            if(yes) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}