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
    int n, m;
    while (cin >> n >> m)
    {
        pr x[n];
        map<int, int> mp;
        fr(i, 0, n)
        {
            cin >> x[i].first;
            x[i].second = i + 1;
        }
        sort(x, x + n);
        mp[x[0].first] = (x[0].second);
        fr(i, 1, n)
        {
            if (mp[m - x[i].first] != 0)
            {
                int a = mp[m - x[i].first];
                int b = x[i].second;
                if (a > b)
                    swap(a, b);
                cout << a << " " << b << endl;
                mp[x[i].first] = x[i].second;
                break;
            }
            if (i == n - 1)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            mp[x[i].first] = x[i].second;
        }
        if (n == 1)
            cout << "IMPOSSIBLE" << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}