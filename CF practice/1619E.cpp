// Problem: E. MEX and Increments
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int pre[MAXN];
int f(int i)
{
	return (i + 1) * i / 2;
}

void sol()
{
	cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		mp[x[i]]++;
		
	}	
	sort(x, x + n);
	for(int i = 0; i < n; i++)
	{
		if(i) pre[i] = pre[i - 1] + x[i];
		else pre[i] = x[i];
	}
	bool yes = 1;
	bool ouo = 1;
	int cnt = 0;
	queue<int> q;
	stack<pii> st;
	int sum = 0;
	int tmp = -1;
	for(int i = 0; i <= n; i++)
	{
		if(tmp == i - 1 && mp[i])
		{
			cout << sum + mp[i] << " ";
			tmp++;
		}
		else if(tmp == i - 1 && mp[i - 1])
		{
			cout << sum + mp[i] << " ";
		}
		else if(!yes)
		{
			cout << -1 << " ";
		}
		else if(st.size())
		{
			pii now = st.top();
			st.pop();
			sum += i - now.F;
			if(now.S > 1)
				st.push({now.F, now.S - 1});
			cout << sum << " ";
			tmp = i;
		}
		else
		{
			cout << -1 << " ";
			yes = 0;
		}
		if(mp[i] > 1)
		{
			st.push({i, mp[i] - 1});
		}
	}
	cout << endl;
	for(int i = 0; i < n; i++)
		cerr << x[i] << " ";
	cerr << endl;
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