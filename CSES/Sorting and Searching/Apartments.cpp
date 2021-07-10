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
        int ans = 0, tmp = -1;
        fr(i, 0, n) cin >> x[i];
        fr(i, 0, m) cin >> y[i];
        sort(x, x + n);
        sort(y, y + m);
        fr(i, 0, m)
        {
            if (tmp >= n)
                break;
            if (x[tmp + 1] > y[i] + k)
                continue;
            fr(j, tmp + 1, n)
            {
                tmp = j;
                if (x[j] > y[i] + k)
                {
                    tmp--;
                    break;
                }
                if (x[j] >= y[i] - k && x[j] <= y[i] + k)
                {
                    ans++;
                    break;
                }
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