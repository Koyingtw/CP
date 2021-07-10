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
        vector<int> v;
        set<int> s;
        fr(i, 0, n)
        {
            cin >> x[i];
        }
        sort(x, x + n);
        v.push_back(0);
        fr(i, 0, n)
        {
            int size = v.size();
            fr(j, 0, size)
            {
                v.push_back(x[i] + v[j]);
                s.insert(x[i] + v[j]);
            }
            if (s.size() != x[i])
            {
                if (i)
                {
                    fr(j, x[i - 1], x[i] + 1)
                    {
                        if (s.count(j) == 0)
                        {
                            cout << j << endl;
                            break;
                        }
                    }
                }
                else
                {
                    fr(j, 0, x[i] + 1)
                    {
                        if (s.count(j) == 0)
                        {
                            cout << j << endl;
                            break;
                        }
                    }
                }
                break;
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