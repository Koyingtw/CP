// Problem: A - First Grid
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	char c[2][2];
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cin >> c[i][j];
		}
	}
	bool yes = 1;
	if(c[0][0] == '#' && c[1][1] == '#' && (c[1][0] != '#' && c[0][1] != '#')) yes = 0;
	if(c[0][1] == '#' && c[1][0] == '#' && (c[1][1] != '#' && c[0][0] != '#')) yes = 0;
	if(c[1][0] == '#' && c[0][1] == '#' && (c[1][1] != '#' && c[0][0] != '#')) yes = 0;
	if(c[1][1] == '#' && c[0][0] == '#' && (c[1][0] != '#' && c[0][1] != '#')) yes = 0;
	if(yes) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}