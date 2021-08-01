#pragma region
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
#pragma endregion
/******************************************************************************/
const int p = 1e9 + 7;

void f(int a[], int b[])
{
    int ans[4];
    ans[0] = a[0] * b[0] + a[1] * b[2];
    ans[1] = a[0] * b[1] + a[1] * b[3];
    ans[2] = a[2] * b[0] + a[3] * b[2];
    ans[3] = a[2] * b[1] + a[3] * b[3];
    fr(i, 0, 4)
    {
        a[i] = ans[i] % p;
    }
}

void sol()
{
    int n;
    while (cin >> n && n != -1)
    {
        int a[4] = {1, 1, 1, 0}, b[4] = {1, 1, 1, 0};
        n--;
        stack<int> s;
        while (n > 0)
        {
            s.push(n % 2);
            n /= 2;
        }
        if (s.size())
        {
            s.pop();
            //f(b, a);
        }
        while (s.size() > 0)
        {
            f(b, b);
            if (s.top())
            {
                f(b, a);
            }
            s.pop();
        }
        cout << b[0] % p << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}