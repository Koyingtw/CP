#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    register int n;
    cin >> n;
    int x[n];
    for (register int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    do
    {
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << "\n";
    } while (next_permutation(x, x + n));
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    sol();
    return 0;
}