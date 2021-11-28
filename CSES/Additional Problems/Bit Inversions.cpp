// Problem: Bit Inversions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1188
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
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	string s;
	cin >> s;
	set<int> pos;
	multiset<int> st;
	pos.insert(0);
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] != s[i - 1]) pos.insert(i);
	}
	pos.insert(s.size());
	int tmp = 0;
	for(int it: pos)
	{
		st.insert(it - tmp);
		tmp = it;
	}
	cin >> n;
	while(n--)
	{
		cin >> m;
		m--;
		s[m] = (!(s[m] - '0')) + '0';
		int r = *pos.upper_bound(m), l = *prev(pos.upper_bound(m));
		st.erase(st.find(r - l));
		pos.erase(m);
		int yes = 0;
		if(m && s[m] == s[m - 1])
		{
			pos.erase(m);
			yes++;
		}
		else if(m)
		{
			pos.insert(m);
			//st.insert(m - l);
		}
		else yes++;
		if(m < s.size() - 1 && s[m] == s[m + 1])
		{
			pos.erase(m + 1);
			yes++;
		}
		else if(m < s.size() - 1)
		{
			pos.insert(m + 1);
			//st.insert(r - m - 1);
		}
		else yes++;
		r = *pos.upper_bound(m), l = *prev(pos.upper_bound(m));
		//if(yes == 2)
		st.insert(r - l);
		cout << *prev(st.end()) << " ";
	}
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