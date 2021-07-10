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
//#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

bool cmp(pr a, pr b)
{
    return a.first > b.first;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int h[n];
        int t[m];
        multiset<int> s;
        fr(i, 0, n)
        {
            cin >> h[i];
            s.insert(h[i]);
        }
        fr(i, 0, m)
        {
            cin >> t[i];
            auto find = s.upper_bound(t[i]);
            if (find == s.begin())
                cout << -1 << endl;
            else
            {
                cout << *(--find) << endl;
                s.erase(find);
            }
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}