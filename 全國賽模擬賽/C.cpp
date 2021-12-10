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

int f(int i)
{
	return i * (i + 1) / 2;
}

void sol()
{
	cin >> n >> m;
	int x[n + 1][m + 1], l[n + 1][m + 1], r[n + 1][m + 1], t[n + 1][m + 1], d[n + 1][m + 1];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> x[i][j];
	}
	stack<pii> st;
	for(int i = 0; i < n; i++)
	{
		l[i][0] = 0;
		st.push({INF, -1});
		st.push({x[i][0], 0});
		for(int j = 1; j < m; j++)
		{
			while(st.size() && st.top().F <= x[i][j])
				st.pop();
			l[i][j] = st.top().S + 1;
			st.push({x[i][j], j});
		}
	}
	while(st.size()) st.pop();
	for(int i = 0; i < n; i++)
	{
		r[i][m - 1] = m - 1;
		st.push({INF, m});
		st.push({x[i][m - 1], m - 1});
		for(int j = m - 2; j >= 0; j--)
		{
			while(st.size() && st.top().F <= x[i][j])
				st.pop();
			r[i][j] = st.top().S - 1;
			st.push({x[i][j], j});
		}
	}
	while(st.size()) st.pop();
	for(int j = 0; j < m; j++)
	{
		t[0][j] = 0;
		st.push({INF, -1});
		st.push({x[0][j], 0});
		for(int i = 1; i < n; i++)
		{
			while(st.size() && st.top().F <= x[i][j])
				st.pop();
			t[i][j] = st.top().S + 1;
			st.push({x[i][j], i});
		}
	}
	while(st.size()) st.pop();
	for(int j = 0; j < m; j++)
	{
		d[n - 1][j] = n - 1;
		st.push({INF, n});
		st.push({x[n - 1][j], n - 1});
		for(int i = n - 2; i >= 0; i--)
		{
			while(st.size() && st.top().F <= x[i][j])
				st.pop();
			d[i][j] = st.top().S - 1;
			st.push({x[i][j], i});
		}
	}
	
	// for(int i = 0; i < n; i++)
	// {
		// for(int j = 0; j < m; j++)
		// {
			// cout << r[i][j] << " ";
		// }
		// cout << endl;
	// }
	
	int ans = 0;
	
	for(int i = 1; i < n - 1; i++)
	{
		for(int j = 1; j < m - 1; j++)
		{
			int tmp = 1;
			tmp = min(j - l[i][j], r[i][j] - j);
			// cout << tmp << endl;
			int a = i - t[i][j];
			int b = d[i][j] - i;
			// cout << a << " " << b << endl;
			if(a <= b)
				tmp *= (f(max(a, b)) - f(abs(a - b)));
			else
				tmp *= f(b);
			ans += tmp;
			ans %= P;
		}
	}
	cout << ans << endl;
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