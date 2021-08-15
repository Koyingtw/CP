#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
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
    vector<bool> x(40000005, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 40000005; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 6500)
            {
                for (int j = i * i; j < 40000005; j += i)
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
    int a, d, n;
    while (cin >> a >> d >> n)
    {
        int last = a + (n - 1) * d, ans = 0;
        auto find = lower_bound(prime.begin(), prime.end(), a);
        for (auto i = find; i != prime.end() && *i <= last; i++)
        {
            if ((*i - a) % d == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

signed main()
{
    Koying;
    pre();
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}