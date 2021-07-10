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
    int n;
    while (cin >> n)
    {
        if ((n * (n + 1)) /2 % 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            int sum = (n * (n + 1)) / 4;
            cout<<"YES"<<endl;
            set<int> s1, s2;
            rf(i, n, 1)
            {
                if (sum - i >= 0)
                {
                    s1.insert(i);
                    sum -= i;
                }
                if (sum == 0)
                    break;
            }
            cout << s1.size() << endl;
            for (int i : s1)
                cout << i << " ";
            cout << endl;
            cout << n - s1.size() << endl;
            fr(i, 1, n + 1)
            {
                if (s1.count(i) == 0)
                    cout << i << " ";
            }
            cout << endl;
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}