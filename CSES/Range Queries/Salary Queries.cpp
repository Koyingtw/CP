// Problem: Salary Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1144
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma GCC optimize("O3")
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
int x[MAXN], BIT[4 * MAXN];
struct Q
{
	char q;
	int a, b;
}Q[MAXN];

void update(int q, int val)
{
	while(q < 4 * MAXN)
	{
		BIT[q] += val;
		q += lowbit(q);
	}
}
int query(int q)
{
	int cnt = 0;
	while(q)
	{
		cnt += BIT[q];
		q -= lowbit(q);
	}
	return cnt;
}
vector<int> v{0};
void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		v.pb(x[i]);
	}
	char q;
	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> Q[i].q >> Q[i].a >> Q[i].b;
		if(Q[i].q == '!') v.pb(Q[i].b);
		else
		{
			v.pb(Q[i].a);
			v.pb(Q[i].b);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
		update(x[i], 1);
	}
	for(int i = 0; i < m; i++)
	{
		// cout << Q[i].q << " " << Q[i].a << " " << Q[i].b << endl;
		if(Q[i].q == '!')
		{
			update(x[Q[i].a], -1);
			x[Q[i].a] = lower_bound(v.begin(), v.end(), Q[i].b) - v.begin();
			update(x[Q[i].a], 1);
		}
		else
		{
			a = lower_bound(v.begin(), v.end(), Q[i].a) - v.begin() - 1;
			b = lower_bound(v.begin(), v.end(), Q[i].b) - v.begin();
			assert(a <= b);
			cout << query(b) - query(a) << endl;
		}
	}
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