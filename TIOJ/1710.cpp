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
#define lowbit(x) x &(-x)
#define MAXN 100005
struct BIT
{
    int arr[MAXN];
    void update(int id, int val)
    {
        while (id < MAXN)
        {
            arr[id] += val;
            id += lowbit(id);
        }
    }
    int query(int id)
    {
        int sum = 0;
        while (id)
        {
            sum += arr[id];
            id -= lowbit(id);
        }
        return sum;
    }
} bit1, bit2;

void sol()
{
    int n;
    cin >> n;
    MEM(bit1.arr, 0);
    MEM(bit2.arr, 0);
    int x[n];
    int sum[n] = {0}, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum[i] = bit1.query(x[i]);
        bit1.update(x[i], 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int qq = bit2.query(MAXN - x[i]);
        ans += sum[i] * qq;
        bit2.update(MAXN - x[i], 1);
    }
    cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}