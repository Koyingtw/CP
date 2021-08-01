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

int f(int x, int y, int p)
{
    if (y == 1)
        return x;
    if (y == 0)
        return 1;
    if (y % 2)
    {
        return (f(x, y - 1, p) * x) % p;
    }
    else
    {
        int a = f(x, y / 2, p);
        return (a * a) % p;
    }
}

void sol()
{
    int x, y, p;
    while (cin >> x >> y >> p)
    {
        int ans = 1;
        p = INF;
        while (y > 0)
        {
            if (y & 1)
            {
                (ans *= x) %= p;
            }
            y >>= 1;
            (ans *= ans) %= p;
        }
        cout << ans << endl;
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
/*

while (y>0) {
 if (y & 1) // odd, (i-1)-bit of y = 1
 t=(t*xi)%p;
P-2-3. 快速冪
輸入正整數 x, y, 與 p，計算 x
y (mod p)。x, y, p 皆不超過 1e9+9。例如 x=2, 
y=5, p=11，則答案是 10。
Time limit: 1 秒
輸入格式：輸入 x, y, 與 p 在同一行，以空白間隔。
輸出格式：輸出計算結果。
範例輸入：
2 5 11
範例輸出：
10AP325 v:1.2 (20201117)
53
 y>>=1;
 xi=(xi*xi)%p;
 i=i*2; // i is useless, for explanation
 }
 return t
 */