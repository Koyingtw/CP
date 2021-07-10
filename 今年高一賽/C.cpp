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

bool six(int n)
{
    if ((n % 6 == 1 || n % 6 == 5))
        return true;
    else
        return false;
}
vector<int> prime;
void pre()
{
    vector<bool> x(46341, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 46341; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 215)
            {
                for (int j = i * i; j < 46341; j += i)
                {
                    x[j] = false;
                }
            }
            prime.push_back(i);
        }
    }
}

void sol()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            int cnt=0;
            fr(i,0,prime.size())
            {
                if(n==1) break;
                while(n%prime[i]==0)
                {
                    cnt++;
                    n/=prime[i];
                }
            }
            if(cnt==1 || cnt==0 || cnt==2 ) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
}


signed main()
{
    Koying
    pre();
    sol();
    return 0;
}