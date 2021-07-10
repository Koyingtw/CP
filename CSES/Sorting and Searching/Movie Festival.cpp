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

bool cmp(pr a, pr b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        fr(i, 0, n)
        {
            cin >> x[i].first >> x[i].second;
        }
        sort(x, x + n, cmp);
        int tmp = x[0].second;
        int ans = 1;
        fr(i, 1, n)
        {
            if (x[i].first < tmp)
                continue;
            else
            {
                ans++;
                tmp = x[i].second;
            }
        }
        DB(ans);
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}