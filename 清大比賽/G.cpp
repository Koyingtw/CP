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
    string s;
    while(cin>>s)
    {
        int x=0,y=0;
        fr(i,0,s.size())
        {
            switch (s[i])
            {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            }
        }
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}