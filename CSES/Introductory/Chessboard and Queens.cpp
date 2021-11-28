// Problem: Chessboard and Queens
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1624
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
bitset<8> v;
bitset<20> l1, l2;
string s[8];
int ans = 0;

void dfs(int x, int y)
{
	if(x == 7)
	{
		ans++;
	}
	else
	{
		for(int i = 0; i < 8; i++)
		{
			if(v[y] || l1[x - y + 8] || l2[x + y])
				continue;
			
			if(s[x + 1][i] != '*')
			{
				v[y] = 1;
				l1[x - y + 8] = 1;
				l2[x + y] = 1;
				dfs(x + 1, i);
				v[y] = 0;
				l1[x - y + 8] = 0;
				l2[x + y] = 0;
			}
		}
	}
	return;
}
void sol()
{
	for(int i = 0; i < 8; i++) cin >> s[i];
	for(int i = 0; i < 8; i++)
	{
		if(s[0][i] != '*')
		{
			v[i] = 1;
			l1[0 - i + 8] = 1;
			l2[i] = 1;
			dfs(0, i);
			v[i] = 0;
			l1[0 - i + 8] = 0;
			l2[i] = 0;
		}
	}
	put(ans);
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