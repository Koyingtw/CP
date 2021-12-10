// Problem: D - Rectangles
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
#define MAXN 20005
#define MAXM 1000005 
int n, m;
pii x[MAXN];
set<int> s[2 * MAXN];
void sol()
{
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].F >> x[i].S;
		v.pb(x[i].F);
		v.pb(x[i].S);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 0; i < n; i++)
	{
		x[i].F = lower_bound(v.begin(), v.end(), x[i].F) - v.begin();
		x[i].S = lower_bound(v.begin(), v.end(), x[i].S) - v.begin();
		s[x[i].F].insert(x[i].S);
	}
	sort(x, x + n);
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)	
		{
			if(x[i].F != x[j].F)
			{
				//i = j;
				break;
			}
			for(int k = x[i].F + 1; k < MAXN; k++)
			{
				if(s[k].count(x[i].S) && s[k].count(x[j].S))
					ans++;
			}
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