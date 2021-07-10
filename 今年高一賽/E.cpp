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
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define DB(a) cout << a << endl;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
void sol()
{
    int n,k;
    while(cin>>n>>k)
    {
        string s;
        cin>>s;
        string ans;
        ans+=s[0];
        int tmp=s.size();
        rf(i,s.size()-1,1) if(s[i]>=s[0]) tmp=i;
        fr(i,1,tmp)
        {
            ans+=s[i];
        }
        string ss=ans;
        while(1)
        {
            if(ans.size()>=k) break;
            else ans+=ans;
        }
        fr(i,0,k) cout<<ans[i];
        cout<<endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}