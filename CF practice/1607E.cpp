// Problem: E. Robot on the Board 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/E
// Memory Limit: 256 MB
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
	cin >> n >> m;
	cin.ignore();
	string s;
	cin >> s;
	pii mx = {0, 0}, my = {0, 0};
	int tmpx = 0, tmpy = 0;
	pii ans = {-1, -1};
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'L')
			tmpy--;
		if(s[i] == 'R')
			tmpy++;
		if(s[i] == 'U')
			tmpx--;
		if(s[i] == 'D')
			tmpx++;
		cmin(mx.F, tmpx);
		cmax(mx.S, tmpx);
		cmin(my.F, tmpy);
		cmax(my.S, tmpy);
		if(mx.S - mx.F + 1 > n || my.S - my.F + 1 > m)
		{
			ans = {-mx.F - (s[i] == 'U') + 1, -my.F - (s[i] == 'L') + 1};
			break;
		}
	}
	if(ans.F != -1)
		cout << ans.F << " " << ans.S << endl;
	else cout << n - mx.S << " " << m - my.S << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}