// Problem: F. Reverse
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/F
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
int dp[60][60];
int cnt1 = 0, cnt2 = 0;
map<string, bool> mp;
int LIS(string a, string b)
{
	MEM(dp, 0);
	for(int i = 1; i < a.size(); i++)
		for(int j = 1; j < b.size(); j++)
		{
			if(a[i] == a[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
		}
	return dp[a.size() - 1][b.size() - 1];
}

bool dfs(string n, string m)
{
	if(n == m) return 1;
	if((mp[n] || n.size() > m.size() || LIS(n, m) != n.size() - 1)) return 0;
	mp[n] = 1;
	bool rtn = 0;
	string tmp = n + "1";
	reverse(tmp.begin() + 1, tmp.end());
	// tmp = "$" + tmp;
	rtn |= dfs(tmp, m);
	bool ouo = 1;
	tmp = "$";
	for(int i = n.size() - 1; i > 0; i--)
	{
		if(n[i] == '0' && ouo)
			continue;
		else
		{
			ouo = 0;
			tmp += n[i];
		}
	}
	// cout << tmp << endl;
	rtn |= dfs(tmp, m);
	return rtn;
}

void sol()
{
	string n = "$", m = "$";
	int a, b;
	cin >> a >> b;
	string tmp;
	while(a)
	{
		tmp += (a & 1) + '0';
		// cnt1 += !(a & 1);
		a >>= 1;
	}
	bool ouo = 0;
	for(int i = 0; i < tmp.size(); i++)
	{
		if(tmp[i] == '0' && ouo)
		{
			cnt1++;
			continue;
		}
		else
		{
			ouo = 0;
			n += tmp[i];
		}
	}
	tmp = "";
	while(b)
	{
		tmp += (b & 1) + '0';
		// cnt2 += !(b & 1);
		b >>= 1;
	}
	ouo = 0;
	for(int i = 0; i < tmp.size(); i++)
	{
		if(tmp[i] == '0' && ouo)
		{
			cnt2++;
			continue;
		}
		else
		{
			ouo = 0;
			m += tmp[i];
		}
	}
	// cout << n << " " << m << endl;
	if(dfs(n, m))
		cout << "YES" << endl;
	else
	{
		// cout << "ouo" << endl;
		reverse(n.begin() + 1, n.end());
		// n = "$" + n;
		if(dfs(n, m))
			cout << "YES" << endl;
		
	 	else
	 	{
	 		string tmp = "$";
	 		ouo = 1;
	 		// reverse(n.begin() + 1, n.end());
			for(int i = n.size() - 1; i > 0; i--)
			{
				if(n[i] == '0' && ouo)
					continue;
				else
				{
					ouo = 0;
					tmp += n[i];
				}
			}
			// cout << tmp << endl;
			if(dfs(tmp, m))
				cout << "YES" << endl;
			else 
			 	cout << "NO" << endl;
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