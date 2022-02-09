// Problem: A. Equal or Not Equal
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/A
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
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	string s;
	cin >> s;
	bool yes = 1;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == 'N') {
			bool chk = 1;
			for (int j = 1, now; j < s.size(); j++) {
				now = (i + j) % s.size();
				chk &= s[now] == 'E';
			}
			yes &= !chk;
		}
	}
	if (yes) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
		cin.ignore();
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}