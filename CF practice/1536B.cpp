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

void sol()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;

    queue<string> q;
    for (int i = 0; i < 26; i++)
    {
        string a(1, ('a' + i));
        q.push(a);
    }
    while (1)
    {
        string now = q.front();
        q.pop();
        if (s.find(now) == string::npos)
        {
            cout << now << endl;
            break;
        }
        for (int i = 0; i < 26; i++)
        {
            string a(1, ('a' + i));
            q.push(now + a);
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}