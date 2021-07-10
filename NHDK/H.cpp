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
    int n;
    while(cin>>n)
    {
        set<int> x;
        fr(i,0,n)
        {
            string s;
            cin>>s;
            int tmp=pow(26,10);
            int sum=0;
            fr(i,0,s.size())
            {
                sum+=(s[i]-'a')*tmp;
                tmp/=26;
            }
            auto find = upper_bound(x.begin(),x.end(),sum);
            if(find == x.end()) cout<<-1<<endl;
            else
            {
                int a=*find;
                string ans; 
                tmp=pow(26,10);
                while(a)
                {
                    cout<<a/tmp<<endl;;
                    char c='a'+a/tmp;
                    DB(c);
                    ans+=c;
                    a%=tmp;
                    tmp/=26;
                }
                DB(ans)
            }
            x.insert(sum);
            
        }
    }
}

void sol1()
{
    int n;
    cin>>n;
    cin.ignore();
    set<string> x;
    fr(i,0,n)
    {
        string s;
        cin>>s;
        string ss;
        fr(i,0,s.size())
        {
            ss+='z'-s[i];
        }
        auto find=x.end();
        if(x.size()) find = lower_bound(x.begin(),x.end(),ss);
        if(x.size()==0 || find == x.end()) DB(-1)
        else
        {
            string ans=*find;
            fr(i,0,ans.size())
            {
                cout<<(char)('z'-ans[i]);
            }
            cout<<endl;
        }
        x.insert(ss);
    }
    cout<<endl;
}

signed main()
{
    Koying
    sol1();
    return 0;
}