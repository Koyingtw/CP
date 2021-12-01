// Problem: D - Longest X
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_d
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int pre[MAXN];
void sol()
{
	string s;
	cin >> s;
	cin >> n;
	for(int i = 0; i < s.size(); i++)
	{
		pre[i + 1] = pre[i] + (s[i] == 'X');
	}
	int ans = 0;
	int l = 1, r = 0;
	for(l = 1; l <= s.size() && r <= s.size(); l++)
	{
		while(r - l + 2 - (pre[r + 1] - pre[l - 1]) <= n && r < s.size())
		{
			cmax(ans, r - l + 1);
			r++;
		}
		cmax(ans, r - l + 1);
		// cout << l << " " << r << endl;
	}
	// cout << pre[6] - pre[1] << endl;
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