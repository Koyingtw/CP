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
int Convert(string _data, int _len)
{
    int result = 0;
    int base = 16;
    int _chr = 0;

    for (int i = 0; i < _len - 2; i++)
    {
        base *= 16;
    }

    for (int i = 0; i < _len; i++)
    {
        _chr = (char)_data[i];
        if (_chr >= 48 and _chr <= 57)
        {
            _chr -= 48;
        }
        else if (_chr >= 65 and _chr <= 90)
        {
            _chr -= 55;
        }
        else if (_chr >= 97 and _chr <= 122)
        {
            _chr -= 87;
        }
        result += _chr * base;
        base /= 16;
        cout << result << endl;
    }
    return result;
}
void sol()
{
    cout << Convert("a90", 3) << endl;
    //2704 正常
    cout << Convert("a990", 4) << endl;
    //-22128 ？？？？
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