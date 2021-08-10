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
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

bool six(int n)
{
    if ((n % 6 == 1 || n % 6 == 5))
        return true;
    else
        return false;
}
vector<int> prime;
void pre()
{
    vector<bool> x(46341, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 46341; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 215)
            {
                for (int j = i * i; j < 46341; j += i)
                {
                    x[j] = false;
                }
            }
            prime.push_back(i);
        }
    }
}
void sol()
{
    int n;
    cin >> n;

    pr ans = {2, 1};
    if (n % 2)
    {
        cout << 2 << " " << n - 1 << endl;
    }
    else
    {
        cout << 2 << " " << 4 << endl;
    }
}

signed main()
{
    Koying;
    //pre();
    int t = 1;
    while (cin >> t)
        while (t--)
        {

            sol();
            END
        }
    return 0;
}