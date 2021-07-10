/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define DB(a) cout << a << endl; 
#define stop system("pause");
#define MEM(x,n) memset(x,n,sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
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
            cin.ignore();
            string s;
            getline(cin,s);
            map<int,int> m;
            fr(i,0,n)
            {
                if(s[i]!=' ') 
                {
                    if(s[i]<='Z') 
                    {
                        m[s[i]]++;
                        m[s[i]+32]++;
                    }
                    else
                    {
                        m[s[i]]++;
                        m[s[i]-32]++;
                    }
                }
            }
            fr(i,0,n)
            {
                if(s[i]!=' ')
                {
                    if(s[i]>='A' && s[i]<='Z')
                    {
                        int a=m[(int)s[i]];
                        a+=s[i]-'A';
                        a%=26;
                        s[i]='A'+a;
                        //cout<<a<<" ";
                    }
                    else
                    {
                        int a=m[(int)s[i]];
                        a+=s[i]-'a';
                        a%=26;
                        s[i]='a'+a;
                        //cout<<a<<" ";
                    }
                }
            }
            cout<<s<<endl;
        }
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}