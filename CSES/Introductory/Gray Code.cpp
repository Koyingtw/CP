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
vector<string> v;

void pre()
{
    int n = 17, cnt = 1;
    v.push_back("0");
    v.push_back("1");
    fr(i, 2, n + 1)
    {
        int dis = pow(2, i - 1);
        rf(j, dis - 1, 0)
        {
            v.push_back(to_string(0) + v[cnt - j]);
        }
        fr(j, 0, dis)
        {
            v.push_back(to_string(1) + v[cnt - j]);
        }
        cnt += dis * 2;
    }
}

void sol()
{
    int n;

    while (cin >> n)
    {
        string s;
        int dis = pow(2, n);
        int cnt = 0;
        fr(i, 1, n)
        {
            cnt += pow(2, i);
        }
        fr(i, cnt, cnt + dis)
        {
            cout << v[i] << endl;
        }
    }
}

signed main()
{
    Koying
    pre();
    sol();
    return 0;
}