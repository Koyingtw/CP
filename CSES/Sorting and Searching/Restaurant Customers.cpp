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
int n;
bool cmp(pr a, pr b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void sol()
{
    while (cin >> n)
    {
        vector<pr> v;
        fr(i, 0, n)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, 1});
            v.push_back({b, -1});
        }
        sort(v.begin(), v.end());
        int ans = 0, mx = 0;
        for (pr i : v)
        {
            ans += i.second;
            mx = max(ans, mx);
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