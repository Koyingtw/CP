// Problem: Maximum Subarray Sum II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1644
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
const int INF = 1e15;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol()
{
	int a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		if(i) x[i] += x[i - 1];
	}
	deque<pii> q;
	q.push_front({0, -1});
	int ans = -INF;
	for(int i = a - 1; i < n; i++)
	{
		while(q.back().S < i - b)
			q.pop_back();
		cmax(ans, x[i] - q.back().F);
		while(q.size() && q.front().F > x[i - a + 1])
			q.pop_front();
		cmax(ans, x[i] - q.back().F);
		q.push_front({x[i - a + 1], i - a + 1});
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