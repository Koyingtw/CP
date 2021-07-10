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
    int n;
    while (cin >> n)
    {
        int x[n];
        int mn = 0, mx = 0;
        cin >> x[0];
        mx = x[0];
        set<int> s;
        s.insert(0);
        fr(i, 1, n)
        {
            cin >> x[i];
            x[i] += x[i - 1];
            s.insert(x[i - 1]);
            mx = max(mx, x[i] - *s.begin());
        }
        cout << mx << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}