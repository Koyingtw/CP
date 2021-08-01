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

int XOR(int a, int b, int k)
{
    int tmp = 1;
    int sum = 0;
    while (a || b)
    {
        sum += tmp * ((a % k + b % k) % k);
        a /= k;
        b /= k;
        tmp *= k;
    }
    return sum;
}

void sol()
{
    int n, k, a = 0;
    cin >> n >> k;
    int tmp = 0;
    //cout << XOR(0, 7, 3) << endl;
    fr(i, 0, n)
    {
        int a;
        int out = XOR(tmp, i, k);
        cout << out << endl;
        cin >> a;
        tmp = XOR(tmp, out, k);
        if (a)
            break;
    }
}

signed main()
{
    //Koying;
    int t = 1;
    cin >> t;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}