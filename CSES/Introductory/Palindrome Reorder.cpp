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

void OUT(string s)
{
    cout << s;
    return;
}

void sol()
{
    string s;
    while (cin >> s)
    {
        map<char, int> m;
        int yes = 2;
        fr(i, 0, s.size())
        {
            m[s[i]]++;
        }
        for (auto i : m)
        {
            if (i.second % 2)
                yes--;
        }
        if (yes <= 0)
            cout << "NO SOLUTION" << endl;
        else
        {
            char ct;
            string ans;
            for (auto i : m)
            {
                if (i.second % 2)
                {
                    fr(j, 0, i.second / 2)
                        ans += i.first;
                    ct = i.first;
                }
                else
                {
                    fr(j, 0, i.second / 2)
                        ans += i.first;
                }
            }
            if(yes == 1) ans += ct;
            int sz = ans.size();
            if (yes == 2)
            {
                rf(i, sz - 1, 0)
                    ans += ans[i];
                cout << ans << endl;
            }
            else
            {
                rf(i, sz - 2, 0)
                    ans += ans[i];
                cout << ans << endl;
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