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
#define F first
#define S second
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define DB(a) cout << a << endl;
#define stop system("pause");
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    int n;
    int mn = 100;
    int ans = 0;
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while (ss >> n)
    {
        ans = max(ans, n - mn);
        mn = min(mn, n);
    }
    cout << ans << endl;
    //stop
}

signed main()
{
    Koying
    sol();
    return 0;
}