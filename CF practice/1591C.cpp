// Problem: C. Minimize Distance
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/C
// Memory Limit: 256 MB
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
#define all(v) v.begin(), v.end()
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

bool cmp(int a, int b)
{
	return abs(a) > abs(b);
}

void sol()
{
	cin >> n >> m;
	vector<int> v, vv;
	for(int i = 0; i < n; i++)	
	{
		cin >> x[i];
		if(x[i] > 0)
			v.pb(x[i]);
		else vv.pb(x[i]);
	}
	sort(all(v), greater<int>());
	sort(all(vv));
	
	int ans = 0, now = 0, ans2 = 0;
	int tmp = 0;
	for(int i = 0; i < v.size(); i += m)
	{
		int mx = 0, mn = INF;
		for(int j = i; j < i + m && j < v.size(); j++)
		{
			cmax(mx, v[j]);
			cmin(mn, v[j]);
			now = v[j];
		}
		ans += abs(mx) + abs(mn) + abs(mx - mn);
		now = 0;
	}
	for(int i = 0; i < vv.size(); i += m)
	{
		int mx = 0, mn = INF;
		for(int j = i; j < i + m && j < vv.size(); j++)
		{
			cmax(mx, abs(vv[j]));
			cmin(mn, abs(vv[j]));
			now = vv[j];
		}
		ans += abs(mx) + abs(mn) + abs(mx - mn);
		now = 0;
	}
	int ouo = 0;
	if(v.size())
		cmax(ouo, v[0]);
	if(vv.size())
		cmax(ouo, -(vv[0]));
	// cmax(ouo, max(abs(v[0]), abs(v[n - 1])));
	// cout << ans << " " << ouo << endl;
	cout << ans - ouo << endl;
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