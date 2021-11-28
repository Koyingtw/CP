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
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define DE cerr
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
struct BIT{
	#define MAXN 200005
	int arr[MAXN];
	int query(int x)
	{
		int sum = 0;
		while(x)
		{
			sum += arr[x];
			x -= lowbit(x);
		}
		return sum;
	}
	void query(int x, int val)
	{
		while(x < MAXN)
		{
			arr[x] += val;
			x += lowbit(x);
		}
	}
}
void sol()
{
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