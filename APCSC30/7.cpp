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
    vector<bool> x(500000, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 500000; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 4000)
            {
                for (int j = i * i; j < 500000; j += i)
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
    while (cin >> n)
    {
        bool yes = (n > 1);
        for (int i : prime)
        {
            if (i > sqrt(n))
                break;
            if (n % i == 0)
            {
                if (n != i)
                    yes = 0;
                break;
            }
        }
        if (yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main()
{
    Koying;
    pre();
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}