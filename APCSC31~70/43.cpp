#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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
struct in
{
    int K;
} in;

vector<int> Qs;
vector<bool> chk1, chk2, chk3; // i, 對角1, 對角2
int cnt = 0;
void dfs(int i)
{
    if (i == in.K)
    {
        for (int j = 0; j < in.K; j++)
        {
            for (int k = 0; k < in.K; k++)
            {
                if (k == Qs[j])
                    cout << 'Q';
                else
                    cout << '*';
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < in.K; j++)
        {
            if (chk1[j] || chk2[i + j] || chk3[i - j + in.K - 1])
                continue;
            else
            {
                chk1[j] = 1, chk2[i + j] = 1, chk3[i - j + in.K - 1] = 1;
                Qs[i] = j;
                dfs(i + 1);
                chk1[j] = 0, chk2[i + j] = 0, chk3[i - j + in.K - 1] = 0;
            }
        }
        return;
    }
}

void sol()
{
    while (cin >> in.K)
    {
        Qs.resize(in.K);
        chk1.resize(in.K);
        chk2.resize(in.K * 2 - 1);
        chk3.resize(in.K * 2 - 1);
        dfs(0);
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