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
    int n;
    while(cin>>n)
    {
        string s,fin;
        cin.ignore();
        int ans=0;
        cin>>s;
        fr(i,0,n)
        {
            if(i!=n-1)
            {
                fin+=s[i];
                fin+="#";
            }
            else fin+=s[i];
        }
        fr(i,n-1,n*2-1)
        {
            bool yes=1;
            fr(j,i+1,n*2-1)
            {
                if(fin[j]!=fin[2*i-j]) 
                {
                    yes=0;
                    break;
                }
            }
            if(yes)
            {
                int ans=2*n-1;
                ans-=2*(ans-i);
                ans=ans/2+ans%2;
                if(ans<0) ans=0;
                cout<<ans<<endl;
                break;
            }
        }
        cout<<ans<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}