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
const int P = 1000000007;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}

int POW(int n)
{
    stack<int> s;
    int sum = 2;
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    while (n)
    {
        s.push(n % 2);
        n /= 2;
    }
    s.pop();
    while (!s.empty())
    {
        if (s.top())
        {
            sum *= sum;
            sum *= 2;
        }
        else
            sum *= sum;
        s.pop();
        sum %= P;
    }
    return sum;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        cout << POW(n) % P << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}