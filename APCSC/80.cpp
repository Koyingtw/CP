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

vector<string> v;

void pre()
{
    int n = 17, cnt = 1;
    v.push_back("0");
    v.push_back("1");
    fr(i, 2, n + 1)
    {
        int dis = pow(2, i - 1);
        rf(j, dis - 1, 0)
        {
            v.push_back(to_string(0) + v[cnt - j]);
        }
        fr(j, 0, dis)
        {
            v.push_back(to_string(1) + v[cnt - j]);
        }
        cnt += dis * 2;
    }
}

void sol()
{
    int n = 5;
    int dis = pow(2, n);
    int cnt = 0;
    fr(i, 1, n)
    {
        cnt += pow(2, i);
    }
    string s;
    while (cin >> s)
    {

        fr(i, cnt, cnt + dis)
        {
            cout << v[i] << endl;
        }
    }
}
signed main()
{
    Koying
    sol();
    return 0;
}