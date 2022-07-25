// Problem: D. Colorful Stamp
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/D
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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol() {
	cin >> n;
	string s;
	cin >> s;
	bool yes = 1;
	map<char, int> mp;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			yes &= (mp.size() % 2 == 0);
			mp.clear();
		}
		else {
			mp[s[i]]++;
		}
	}
	yes &= (mp.size() % 2 == 0);
	if (yes)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}