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
using namespace std;
const int N = 2e5;
void OUT(string s)
{
    cout << s;
    return;
}
int x[N], y[N];
bool b[N];
void sol()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int ans = 0, tmp = 0;
        int x[n], y[m];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < m; i++)
            cin >> y[i];
        sort(x, x + n);
        sort(y, y + m);
        for (int i = 0; i < n; i++)
        {
            if (tmp == m)
                break;
            if (y[tmp] <= x[i] + k && y[tmp] >= x[i] - k)
            {
                ans++;
                tmp++;
            }
            else if (y[tmp] > x[i] + k)
                continue;
            else
            {
                i--;
                tmp++;
            }
        }
        cout << ans << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}