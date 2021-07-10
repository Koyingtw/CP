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
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    string ans = "hello,ballooncup7th!";
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        bool yes = 1;
        int size = s.size();
        fr(i, 0, size)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                if (s[i] - 'a' != ans[i] - 'a')
                    yes = 0;
            }
            else if (s[i] <= 'Z' && s[i] >= 'A')
            {
                if (s[i] - 'A' != ans[i] - 'a')
                    yes = 0;
            }
            else if (s[i] != ans[i])
                yes = 0;
        }
        if (yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}