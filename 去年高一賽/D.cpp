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

void sol()
{
    string s,a;
    while(cin>>s)
    {
        cin>>a;
        string ans;
        int k=s.size()+1;
        cout<<k<<endl;
        for(int i=0;i<a.size();i+=10)
        {
            stack<char> c;
            string ss;
            fr(j,i,i+10) ss+=a[j];

            stringstream sm;
            sm<<ss;
            int a;
            sm>>a;
            cout<<a<<endl;
            /*************/
            //stack 
            while(a)
            {
                if(a%k==0) c.push('\n');
                else 
                {
                    c.push(s[a%k-1]);
                    cout<<a%k<<" ";
                }
                
                a/=k;
            }
            
            while(!c.empty())
            {
                cout<<c.top();
                c.pop();
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