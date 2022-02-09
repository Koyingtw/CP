// Problem: A. Forbidden Subsequence
// Contest: Codeforces - Codeforces Round #761 (Div. 2)
// URL: https://codeforces.com/contest/1617/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	string a, b;
	cin >> a >> b;
	map<char, int> mp;
	set<char> st;
	for(char c: a)
	{
		mp[c]++;
		st.insert(c);
	}
	string s;
	for(char c: st)
		if(c <= 'c')
			s += c;
	do
	{
		if(s != b)
		{
			for(char c: s)
			{
				while(mp[c]--)
					cout << c;
				
			}
			for(char c = 'd'; c <= 'z'; c++)
				while(mp[c]--)
					cout << c;
			cout << endl;
			return;
		}
	}while(next_permutation(all(s)));
	
	
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