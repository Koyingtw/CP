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
    int n;
    while(cin>>n)
    {
        stack<int> s,cnt;
        cnt.push(1);
        int ans=0;
        fr(i,0,n)
        {
            int a;
            cin>>a;
            if(!(s.empty()))
            {
                int sum=1;
                if(a<s.top()) 
                {
                    ans+=1;
                    s.push(a);
                    cnt.push(1);
                }
                else if(a>s.top())
                {
                    ans+=cnt.top();
                    cnt.top()++;
                }
                else
                {
                    ans++;
                    
                }
            }
            else s.push(a);
        }
        cout<<ans*2<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}