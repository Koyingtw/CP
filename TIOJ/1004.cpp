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
        bool b[n];
        memset(b,1,sizeof(b));
        fr(i,0,n) cout<<b[i]<<" ";
        cout<<endl;
        set<int> s;
        int tmp=0;
        while(s.size()<n-1)
        {
            
            fr(i,0,n)
            {
                if(b[i]==0) continue;
                if(tmp%3==0)
                {
                    b[i]=0;
                    s.insert(i);
                }
                tmp++;
                if(s.size()==n-1) break;
            }
            fr(i,0,n) cout<<b[i]<<" ";
            cout<<endl;
        }
        fr(i,0,n)
        {
            if(b[i]) 
            {
                cout<<i+1<<endl;
                break;
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