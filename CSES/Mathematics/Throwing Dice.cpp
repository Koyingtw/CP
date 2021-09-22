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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int A[6][6], B[6][6];
const int P = 1e9 + 7;
void init()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0)
                A[i][j] = 1, B[i][j] = 1;
            else
                A[i][j] = (j == i - 1), B[i][j] = A[i][j];
        }
    }
}

void multi(int id)
{
    if (id == 0)
    {
        int tmp[6][6];
        MEM(tmp, 0);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int cnt = 0;
                for (int k = 0; k < 6; k++)
                {
                    cnt += A[i][k] * A[k][j];
                    cnt %= P;
                }
                tmp[i][j] = cnt;
            }
        }
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                A[i][j] = tmp[i][j];
    }
    else
    {
        int tmp[6][6];
        MEM(tmp, 0);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int cnt = 0;
                for (int k = 0; k < 6; k++)
                {
                    cnt += A[i][k] * B[k][j];
                    cnt %= P;
                }
                tmp[i][j] = cnt;
            }
        }
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                A[i][j] = tmp[i][j] % P;
    }
}

void sol()
{
    int n;
    while (cin >> n)
    {
        if (n <= 6)
        {
            cout << pow(2, n - 1) << endl;
            continue;
        }
        if (n == 7)
        {
            cout << 63 << endl;
            continue;
        }
        init();
        stack<int> s;
        n -= 6;
        while (n)
        {
            s.push(n % 2);
            n >>= 1;
        }
        s.pop();
        while (s.size())
        {
            multi(0);
            if (s.top())
                multi(1);
            s.pop();
        }
        int ans = 0;
        for (int i = 0; i < 6; i++)
        {
            //cout << A[0][i] << " ";
            ans += A[0][i] * pow(2, 6 - i - 1);
            ans %= P;
        }
        //cout << endl;
        cout << ans << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}