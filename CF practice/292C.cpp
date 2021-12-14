// Problem: C. Drazil and Factorial
// Contest: Codeforces - Codeforces Round #292 (Div. 2)
// URL: https://codeforces.com/contest/515/problem/C
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
int f[10];
map<int, int> mp;
void pre()
{
	int sum = 1;
	f[0] = 1;
	for(int i = 1; i < 10; i++)
	{
		f[i] = f[i - 1] * i;
		mp[f[i]] = i;
		// cout << f[i] << " ";
	}
	// cout << endl;
}

bool check(int a)
{
	int tmp = a;
	bool yes = 1;
	for(int i = 2; i < 10; i++)
	{
		while(tmp % f[i] == 0)
		{
			tmp /= f[i];
		}
	}
		// if(a % f[i] == 0) return 1;
	if(tmp == 1) return 1;
	return 0;
}
vector<int> ans;
bool yes = 0;
void dfs(int tmp, int i, stack<int> st)
{
	st.push(i);
	tmp /= f[i];
	if(tmp == 1)
	{
		if(yes == 0)
		{
			while(st.size())
			{
				ans.pb(st.top());
				st.pop();
			}
			yes = 1;
		}
		return;
	}
	for(int j = i; j < 10; j++)
	{
		if(tmp % f[j] == 0)
			dfs(tmp, j, st);
	}
	st.pop();
}

void sol()
{
	cin >> n;
	cin.ignore();
	pre();
	string s;
	cin >> s;

	int tmp = 1;
	for(char c: s)
	{
		if(c == '0' || c == '1') continue;
		tmp = f[c - '0'];
		// cout << tmp << endl;
		stack<int> st;
		yes = 0;
		for(int i = 2; i < 10; i++)
			if(tmp % f[i] == 0)
			{
				dfs(tmp, i, st);
			}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for(int it: ans) cout << it;
	cout << endl;
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