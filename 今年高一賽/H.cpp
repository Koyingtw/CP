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
#define DB(a) cout<<a<<endl;
using namespace std;

void OUT(string s) {cout<<s; return;} 

void sol()
{
    string s;
    int t;
    while(cin>>s>>t)
    {
        int n;
        cin>>n;
        int x[n];
        vector<int> v,l,r;
        fr(i,0,n)
        {
            cin>>x[i];
            int tmp=i+1;
            fr(j,0,v.size()) 
            {
                if(tmp-v[j]==0) 
                {
                    tmp++;
                }
                if(tmp-v[j]==-1)
                {
                    tmp--;
                }
            }
            if(x[i]>tmp)
            {
                fr(j,tmp,x[i])
                {
                    v.push_back(j);
                }
            }
            if(x[i]<tmp)
            {
                rf(j,tmp-1,x[i])
                {
                    v.push_back(j);
                }
            }
            
        }
        fr(m,0,5)
        {
            int tmp=i+1;
            fr(j,0,v.size()) 
            {
                if(tmp-v[j]==0) 
                {
                    tmp++;
                }
                if(tmp-v[j]==-1)
                {
                    tmp--;
                }
            }
            if(x[i]>tmp)
            {
                fr(j,tmp,x[i])
                {
                    v.push_back(j);
                }
            }
            if(x[i]<tmp)
            {
                rf(j,tmp-1,x[i])
                {
                    v.push_back(j);
                }
            }
        }
        OUT(s);
        cout<<" "<<t<<endl;
        cout<<v.size()<<endl;
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}