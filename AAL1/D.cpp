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
int f(int x)
{
    int ouo = 0;
    while (x)
    {
        ouo += x % 10;
        x /= 10;
    }
    return ouo;
}
int cnt[63];
int l, r, v1, v2;
void pre()
{
    for (int i = l; i <= r; i++)
    {
        cnt[f(i)]++;
    }
    for (int i = 1; i < 63; i++)
        cnt[i] = cnt[i - 1] + cnt[i];
}

void sol()
{
    while (cin >> l >> r >> v1 >> v2)
    {
        pre();
        int a = 1, b = 1, tmp = cnt[1];
        for(int i = 1; i < v1; i++)
        {
            
        }
        else if (tmp > v2)
        {
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    pre();
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}